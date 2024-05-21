#include "Minion.h"

#include <string>

#include <cstdlib>
#include <ctime>
using namespace std;

Minion::Minion(string name, int health, int level) {
  this->name = name;
  this->health = health;
  this->level = level;
  isAlive = true;
  bleed = 0;
}

string Minion::get_name() { return name; }

int Minion::get_health() { return health; }

int Minion::get_level() { return level; }

void Minion::set_level(int level) { this->level = level; }

int Minion::get_bleed() { return bleed; }

void Minion::set_bleed(int bleed) { this->bleed = bleed; }

bool Minion::get_isAlive() { return isAlive; }

void Minion::set_health(int health) {
  if (health > 0) {
    this->health = health;
  } else {
    this->health = 0;
  }
}

void Minion::checkHealth() {
  if (health <= 0) {
    health = 0;
    isAlive = false;
  } else {
    isAlive = true;
  }
}

void Minion::specialAttack(Character &c1, Character &c2, Character &c3) {
  // Seed the random number generator
  srand(static_cast<unsigned int>(time(0)));

  // Choose a random character
  int randomIndex = rand() % 3;
  Character *targets[3] = {&c1, &c2, &c3};
  Character *target = targets[randomIndex];

  // Deal damage to the chosen character
  int damage = 20; // or any other damage value
}

void Minion::attack(int damage, Attack &object) {}

void Minion::attack(int damage, Character &c1) {

  if (c1.get_isWeakening()) {
    c1.set_health(c1.get_health() - (damage / 2));
  } else if (c1.get_isProtecting()) {
    c1.set_health(c1.get_health() - max(0, damage - c1.getProtectionAmount()));
    c1.resetProtection();
  } else {
    c1.set_health(c1.get_health() - damage);
  }
}

void Minion::attack(int damage, Character &c1, Character &c2) {

  if (c1.get_isWeakening() || c2.get_isWeakening()) {
    c1.set_health(c1.get_health() - (damage / 2));
    c2.set_health(c2.get_health() - (damage / 2));

  } else if (c1.get_isProtecting() || c2.get_isProtecting()) {
    c1.set_health(c1.get_health() - max(0, damage - c1.getProtectionAmount()));
    c2.set_health(c2.get_health() - max(0, damage - c2.getProtectionAmount()));
    c1.resetProtection();

  } else if (c1.get_isAnchoring() || c2.get_isAnchoring()) {

    if (c1.get_isAnchoring()) {
      c1.set_health(c1.get_health() - (damage * 2));
      c1.resetAnchoring();
    } else if (c2.get_isAnchoring()) {
      c2.set_health(c2.get_health() - (damage * 2));
      c2.resetAnchoring();
    }

  } else {
    c1.set_health(c1.get_health() - damage);
    c2.set_health(c2.get_health() - damage);
  }
}

void Minion::attack(int damage, Character &c1, Character &c2, Character &c3) {

  if (c1.get_isWeakening() || c2.get_isWeakening() || c3.get_isWeakening()) {
    c1.set_health(c1.get_health() - (damage / 2));
    c2.set_health(c2.get_health() - (damage / 2));
    c3.set_health(c3.get_health() - (damage / 2));

  } else if (c1.get_isProtecting() || c2.get_isProtecting() ||
             c3.get_isProtecting()) {
    c1.set_health(c1.get_health() - max(0, damage - c1.getProtectionAmount()));
    c2.set_health(c2.get_health() - max(0, damage - c2.getProtectionAmount()));
    c3.set_health(c3.get_health() - max(0, damage - c3.getProtectionAmount()));
    c1.resetProtection();

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

  else {
    c1.set_health(c1.get_health() - damage);
    c2.set_health(c2.get_health() - damage);
    c3.set_health(c3.get_health() - damage);
  }
}
