#include "Game.h"

Game::Game()
    : fighter(nullptr), wizard(nullptr), cleric(nullptr), minion(nullptr),
      miniBoss(nullptr), boss(nullptr) {}

// setters
void Game::setMinion(Minion *minionPtr) { minion = minionPtr; }
void Game::setMiniBoss(MiniBoss *miniBossPtr) { miniBoss = miniBossPtr; }
void Game::setBoss(Boss *bossPtr) { boss = bossPtr; }
void Game::setFighter(Fighter *fighterPtr) { fighter = fighterPtr; }
void Game::setWizard(Wizard *wizardPtr) { wizard = wizardPtr; }
void Game::setCleric(Cleric *clericPtr) { cleric = clericPtr; }
void Game::setMonsterCount(int count) { monsterCount = count; }

int Game::getMonsterCount() { return monsterCount; }

// check if charcaters are dead
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

// round function to handle every round of combat
void Game::round() {

  // Change the "alive" status if character/enemy dies
  fighter->checkHealth();
  wizard->checkHealth();
  cleric->checkHealth();
  minion->checkHealth();
  miniBoss->checkHealth();
  boss->checkHealth();

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

  // equip items if present in inventory

  // equip reaper's blade
  if (fighter->hasItem("Reaper's Blade")) {
    fighter->equipReapersBlade();
  }
  // equip ring of fire
  if (wizard->hasItem("Ring of Fire")) {
    wizard->equipRingOfFire();
  }
  // equip holy water
  if (cleric->hasItem("Holy Water")) {
    fighter->setProtectionAmount(10);
    wizard->setProtectionAmount(10);
    cleric->setProtectionAmount(10);
  }
  // equip life essence
  if (fighter->hasItem("Life Essence")) {
    if (fighter->get_isAlive()) {
      fighter->set_health(fighter->get_health() + 25);
    }
    if (wizard->get_isAlive()) {
      wizard->set_health(wizard->get_health() + 25);
    }
    if (cleric->get_isAlive()) {
      cleric->set_health(cleric->get_health() + 25);
    }
  }
  // equip second chance
  if (fighter->hasItem("Second Chance")) {
    if (!fighter->get_isAlive()) {
      fighter->set_health(50);
      fighter->removeItem("Second Chance");
    }
    if (!wizard->get_isAlive()) {
      wizard->set_health(50);
      fighter->removeItem("Second Chance");
    }
    if (!cleric->get_isAlive()) {
      cleric->set_health(50);
      fighter->removeItem("Second Chance");
    }
  }
  // equip action boost
  if (fighter->hasItem("Action Boost")) {
    fighter->set_actionPoints(6);
  } else {
    fighter->set_actionPoints(5);
  }

  // Give money when enemy is defeated
  if (!minion->get_isAlive()) {
    fighter->set_money(fighter->get_money() + 400);
  }
  if (!miniBoss->get_isAlive()) {
    fighter->set_money(fighter->get_money() + 600);
  }
  if (!boss->get_isAlive()) {
    fighter->set_money(fighter->get_money() + 800);
  }

  // reset weakening ray after every round
  wizard->resetWeakening();

  // increasing monster count if monster dies
  if (!minion->get_isAlive()) {
    setMonsterCount(2);
  }
  if (!miniBoss->get_isAlive()) {
    setMonsterCount(3);
  }

  // Output the result of the round
  std::cout << "Round ended." << std::endl;
}

// load game function
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