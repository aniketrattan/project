#include "Minion.h"

// Constructor definition
Minion::Minion(string name, int health, int level) {
  this->name = name;
  this->health = health;
  this->level = level;
  isAlive = true;
  bleed = 0;
}

// getters definitions
string Minion::get_name() { return name; }
int Minion::get_health() { return health; }
int Minion::get_level() { return level; }
int Minion::get_bleed() { return bleed; }
bool Minion::get_isAlive() { return isAlive; }

// setters definitions
void Minion::set_level(int level) { this->level = level; }
void Minion::set_bleed(int bleed) { this->bleed = bleed; }
void Minion::set_health(int health) {
  if (health > 0) {
    this->health = health;
  } else {
    this->health = 0;
  }
}

// updating is alive status if health goes to zero
void Minion::checkHealth() {
  if (health <= 0) {
    health = 0;
    isAlive = false;
  } else {
    isAlive = true;
  }
}

// Defintions for attacks
void Minion::specialAttack(Character &c1, Character &c2, Character &c3) {
  // Seed the random number generator
  srand(static_cast<unsigned int>(time(0)));

  // Choose a random character
  int randomIndex = rand() % 3;
  Character *targets[3] = {&c1, &c2, &c3};
  Character *target = targets[randomIndex];

  // Deal damage to the chosen character
  int damage = rand() % 11 + 15;

  if (c1.get_isAnchoring() || c2.get_isAnchoring() || c3.get_isAnchoring()) {
    attack(damage, c1);
  } else if (c1.get_isWeakening() || c2.get_isWeakening() || c3.get_isWeakening()) {
    attack((damage / 2), *target);
  } else if (c1.get_isProtecting() || c2.get_isProtecting() || c3.get_isProtecting()) {
    attack((damage - c1.getProtectionAmount()), *target);
  } else {
    attack(damage, *target);
  }
}

// initialization of pure virtual function
void Minion::attack(int damage, Attack &object) {}

// different attack functions
void Minion::attack(int damage, Character &c1) {
  c1.set_health(c1.get_health() - damage);
}

void Minion::attack(int damage, Character &c1, Character &c2) {
  c1.set_health(c1.get_health() - damage);
  c2.set_health(c2.get_health() - damage);
}

void Minion::attack(int damage, Character &c1, Character &c2, Character &c3) {

  // if weakening buff is active, reduce the damage done by minion
  if (c1.get_isWeakening() || c2.get_isWeakening() || c3.get_isWeakening()) {
    c1.set_health(c1.get_health() - (damage / 2));
    c2.set_health(c2.get_health() - (damage / 2));
    c3.set_health(c3.get_health() - (damage / 2));

    // if protection buff is active, reduce the damage done by minion
  } else if (c1.get_isProtecting() || c2.get_isProtecting() ||
             c3.get_isProtecting()) {
    c1.set_health(c1.get_health() - max(0, damage - c1.getProtectionAmount()));
    c2.set_health(c2.get_health() - max(0, damage - c2.getProtectionAmount()));
    c3.set_health(c3.get_health() - max(0, damage - c3.getProtectionAmount()));
    c1.resetProtection();

    // if anchoring buff is active, redirect damage to one character
  } else if (c1.get_isAnchoring() || c2.get_isAnchoring() ||
             c3.get_isAnchoring()) {
    if (c1.get_isAnchoring()) {
      c1.set_health(c1.get_health() - (damage * 3));
      c1.resetAnchoring();
    } else if (c2.get_isAnchoring()) {
      c2.set_health(c2.get_health() - (damage * 3));
      c2.resetAnchoring();
    } else if (c3.get_isAnchoring()) {
      c3.set_health(c3.get_health() - (damage * 3));
    }
  }

  // if no buffs/debuffs are present, do simple damage
  else {
    c1.set_health(c1.get_health() - damage);
    c2.set_health(c2.get_health() - damage);
    c3.set_health(c3.get_health() - damage);
  }
}
