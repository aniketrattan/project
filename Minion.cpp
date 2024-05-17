#include "Minion.h"

#include <string>
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
    isAlive = false;
  }
}

void Minion::attack(int damage, Attack &object) {
  int initialHealth = object.get_health();
  int newHealth = initialHealth - damage;
  if (health < 0) {
    health = 0;
  }
  object.set_health(newHealth);
}

void Minion::attack(int damage, Attack &object, Attack &object1) {
  int initialHealth = object.get_health();
  int newHealth = initialHealth - damage;
  if (health < 0) {
    health = 0;
  }
  object.set_health(newHealth);

  int initialHealth1 = object1.get_health();
  int newHealth1 = initialHealth1 - damage;
  if (health < 0) {
    health = 0;
  }
  object1.set_health(newHealth1);
}

void Minion::attack(int damage, Attack &object, Attack &object1,
                    Attack &object2) {
  int initialHealth = object.get_health();
  int newHealth = initialHealth - damage;
  if (health < 0) {
    health = 0;
  }
  object.set_health(newHealth);

  int initialHealth1 = object1.get_health();

  int newHealth1 = initialHealth1 - damage;
  if (health < 0) {
    health = 0;
  }
  object1.set_health(newHealth1);

  int initialHealth2 = object2.get_health();

  int newHealth2 = initialHealth2 - damage;
  if (health < 0) {
    health = 0;
  }
  object2.set_health(newHealth2);
}
