#include <string>
using namespace std;
#include "Character.h"
#include "Minion.h"

Character::Character(int health) {
  this->health = health;
  isAlive = true;
}

int Character::get_health() { return health; }

void Character::set_health(int health) { this->health = health; }

bool Character::get_isAlive() { return isAlive; }

void Character::attack(int damage, Minion &target) {
  target.set_health(target.get_health() - damage);
}
