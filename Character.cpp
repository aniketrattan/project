#include "Character.h"

// constructor
Character::Character(int health) {
  this->health = health;
  isAlive = true;
}

// getters
int Character::get_health() { return health; }
bool Character::get_isAlive() { return isAlive; }


// setters
void Character::set_health(int health) {
  if (health > 0) {
    this->health = health;
  } else {
    this->health = 0;
  }
}
// updating is alive status if health goes to zero
void Character::checkHealth() {
  if (health <= 0) {
    health = 0;
    isAlive = false;
  } else {
    isAlive = true;
  }
}

