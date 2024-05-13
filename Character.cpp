#include <string>
using namespace std;
#include "Character.h"
#include "Minion.h"

int Character::actionPoints = 5;

Character::Character(int health) {
  this->health = health;
  isAlive = true;
}

int Character::get_health() { return health; }

void Character::set_health(int health) { this->health = health; }

bool Character::get_isAlive() { return isAlive; }

void Character::attack(int damage, Minion &target) {
  target.set_health(target.get_health() - (damage / target.get_level()) );
}

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