#include "Minion.h"

//Default Constructer:
Minion::Minion() {
    name = "";
    health = 0;
    level = 0;
    isAlive = false;
}

// Constructor definition
Minion::Minion(string name, int health, int level) {
  this->name = name;
  this->health = health;
  this->level = level;
  isAlive = true;
}

// getters definitions
string Minion::get_name() { return name; }
int Minion::get_health() { return health; }
int Minion::get_level() { return level; }
bool Minion::get_isAlive() { return isAlive; }

// setters definitions
void Minion::set_level(int level) { this->level = level; }
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


// initialization of pure virtual function
void Minion::attack(int damage, Attack &object) {}

// different attack functions
void Minion::attack(int damage, Character &c1) {
  c1.set_health(c1.get_health() - damage);
}

  