#include "Minion.h"
#include "Character.h"
#include <string>


Minion::Minion(string name, int health, int level) {
  this->name = name;
  this->health = health;
  this->level = level;
  isAlive = true;
}

string Minion::get_name() { return name; }

int Minion::get_health() { return health; }

int Minion::get_level() { return level; }

bool Minion::get_isAlive() { return isAlive; }

void Minion::set_health(int health) { this->health = health; }

void Minion::attack(int damage, Character &target) {
  target.set_health(target.get_health() - damage);
}