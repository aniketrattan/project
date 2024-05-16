#include <string>
using namespace std;
#include "Character.h"


int Character::actionPoints = 5;

Character::Character(int health) {
  this->health = health;
  isAlive = true;
  fire = 0;
  poison = 0;
}

int Character::get_health() { return health; }

void Character::set_health(int health) { this->health = health; }

bool Character::get_isAlive() { return isAlive; }

void Character::checkHealth() {
  if (health <= 0) {
    isAlive = false;
  }
}

int Character::get_actionPoints() { return actionPoints; }

bool Character::useActionPoints(int points) {
  if (actionPoints >= points) {
    actionPoints -= points;
    return true;
  }
  return false; // Insufficient action points
}

void Character::set_fire(int fire) { this->fire = fire; }

int Character::get_fire() { return fire; }

void Character::set_poison(int poison) { this->poison = poison; }

int Character::get_poison() { return poison; }

void Character::attack(Attack& object,int damage) {
  int initialHealth=object.get_health();;
  int newHealth=initialHealth-damage;
  if(newHealth<0){
    newHealth=0;
  }
  object.set_health(newHealth);
}