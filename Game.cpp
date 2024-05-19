#include "Game.h"
#include <iostream>

Game::Game()
    : fighter(nullptr), wizard(nullptr), cleric(nullptr), minion(nullptr),
      miniBoss(nullptr), boss(nullptr) {}

void Game::setMinion(Minion *minionPtr) { minion = minionPtr; }

void Game::setMiniBoss(MiniBoss *miniBossPtr) { miniBoss = miniBossPtr; }

void Game::setBoss(Boss *bossPtr) { boss = bossPtr; }

void Game::setFighter(Fighter *fighterPtr) { fighter = fighterPtr; }

void Game::setWizard(Wizard *wizardPtr) { wizard = wizardPtr; }

void Game::setCleric(Cleric *clericPtr) { cleric = clericPtr; }

void Game::checkEndCondition() {
  if (wizard && wizard->get_isAlive()) {
    return; // Wizard is still alive
  }

  if (cleric && cleric->get_isAlive()) {
    return; // Cleric is still alive
  }

  if (fighter && fighter->get_isAlive()) {
    return; // Fighter is still alive
  }

  std::cout << "Game over" << std::endl;
}

void Game::round() {
  // Apply poison damage to Fighter, Wizard, and Cleric
  fighter->set_health(fighter->get_health() - fighter->get_poison());
  wizard->set_health(wizard->get_health() - wizard->get_poison());
  cleric->set_health(cleric->get_health() - cleric->get_poison());

  // Apply fire damage to Fighter, Wizard, and Cleric
  fighter->set_health(fighter->get_health() - fighter->get_fire());
  wizard->set_health(wizard->get_health() - wizard->get_fire());
  cleric->set_health(cleric->get_health() - cleric->get_fire());

  // Apply bleed damage to Minion, MiniBoss, and Boss
  minion->set_health(minion->get_health() - minion->get_bleed());
  miniBoss->set_health(miniBoss->get_health() - miniBoss->get_bleed());
  boss->set_health(boss->get_health() - boss->get_bleed());

  fighter->set_actionPoints(5);

  // Change the "alive" status if character/enemy dies
  fighter->checkHealth();
  wizard->checkHealth();
  cleric->checkHealth();
  minion->checkHealth();
  miniBoss->checkHealth();
  boss->checkHealth();

  // Give money when enemy is defeated
  if (!minion->get_isAlive()) {
    fighter->set_money(fighter->get_money() + 20);
  }
  if (!miniBoss->get_isAlive()) {
    fighter->set_money(fighter->get_money() + 50);
  }
  if (!boss->get_isAlive()) {
    fighter->set_money(fighter->get_money() + 100);
  }

  // Output the result of the round
  std::cout << "Round ended." << std::endl;
}

void Game::saveGame() {
  // Get the current time
  auto now = std::chrono::system_clock::now();
  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  // Convert the current time to a string
  std::stringstream ss;
  ss << "save_" << std::put_time(std::localtime(&currentTime), "%Y%m%d_%H%M%S")
     << ".dat";
  std::string filename = ss.str();

  std::ofstream file(filename, std::ios::binary);
  if (file.is_open()) {
    // Save health of Fighter, Wizard, and Cleric
    file.write(reinterpret_cast<char *>(fighter->get_health()), sizeof(int));
    file.write(reinterpret_cast<char *>(wizard->get_health()), sizeof(int));
    file.write(reinterpret_cast<char *>(cleric->get_health()), sizeof(int));

    // Save isAlive status of Minion, MiniBoss, and Boss
    file.write(reinterpret_cast<char *>(minion->get_isAlive()), sizeof(bool));
    file.write(reinterpret_cast<char *>(miniBoss->get_isAlive()), sizeof(bool));
    file.write(reinterpret_cast<char *>(boss->get_isAlive()), sizeof(bool));

    file.close();
    std::cout << "Game state saved to " << filename << std::endl;
  } else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

void Game::loadGame(const std::string &filename) {
  std::ifstream file(filename, std::ios::binary);
  if (file.is_open()) {
    // Read health of Fighter, Wizard, and Cleric
    int fighterHealth, wizardHealth, clericHealth;
    file.read(reinterpret_cast<char *>(&fighterHealth), sizeof(int));
    file.read(reinterpret_cast<char *>(&wizardHealth), sizeof(int));
    file.read(reinterpret_cast<char *>(&clericHealth), sizeof(int));

    // Restore health of Fighter, Wizard, and Cleric
    fighter->set_health(fighterHealth);
    wizard->set_health(wizardHealth);
    cleric->set_health(clericHealth);

    // Read isAlive status of Minion, MiniBoss, and Boss
    bool minionAlive, miniBossAlive, bossAlive;
    file.read(reinterpret_cast<char *>(&minionAlive), sizeof(bool));
    file.read(reinterpret_cast<char *>(&miniBossAlive), sizeof(bool));
    file.read(reinterpret_cast<char *>(&bossAlive), sizeof(bool));

    // Restore health of Minion, MiniBoss, and Boss if they were alive
    if (minionAlive)
      minion->set_health(100);
    if (miniBossAlive)
      miniBoss->set_health(250);
    if (bossAlive)
      boss->set_health(500);

    file.close();
    std::cout << "Game state loaded from " << filename << std::endl;
  } else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

Game::~Game() {
  // Clean up allocated memory
  delete fighter;
  delete wizard;
  delete cleric;
  delete minion;
  delete miniBoss;
  delete boss;
}