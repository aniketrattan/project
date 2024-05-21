#include <string>
using namespace std;
#include "Character.h"

int Character::actionPoints = 5;

int Character::money = 0;

bool Character::isProtecting = false;

bool Character::isWeakening = false;

Character::Character(int health) {
  this->health = health;
  isAlive = true;
  fire = 0;
  poison = 0;
}

int Character::get_health() { return health; }

void Character::set_health(int health) {
  if (health > 0) {
    this->health = health;
  } else {
    this->health = 0;
  }
}

bool Character::get_isAlive() { return isAlive; }

void Character::checkHealth() {
  if (health <= 0) {
    health = 0;
    isAlive = false;
  } else {
    isAlive = true;
  }
}

int Character::get_actionPoints() { return actionPoints; }

void Character::set_actionPoints(int actionPoints) {
  this->actionPoints = actionPoints;
}

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

void Character::attack(int damage, Attack &object) {
  int initialHealth = object.get_health();
  int newHealth = initialHealth - damage;
  if (health < 0) {
    health = 0;
  }
  object.set_health(newHealth);
}

int Character::get_money() { return money; }

void Character::set_money(int money) { this->money = money; }

void Character::addItem(const Items &item) { inventory.push_back(item); }

bool Character::hasItem(const string &itemName) const {
  for (const auto &item : inventory) {
    if (item.get_name() == itemName) {
      return true;
    }
  }
  return false;
}

bool Character::removeItem(const string &itemName) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (it->get_name() == itemName) {
      inventory.erase(it);
      return true;
    }
  }
  return false;
}

void Character::weakeningRay() {
  isWeakening = true;
  useActionPoints(1);
}

bool Character::get_isWeakening() { return isWeakening; };

void Character::resetWeakening() { isWeakening = false; }

void Character::protection() {
  isProtecting = true;
  useActionPoints(1);
}

bool Character::get_isProtecting() { return isProtecting; };

void Character::resetProtection() { isProtecting = false; }

void Character::setProtectionAmount(int protectionAmount) {
  this->protectionAmount = protectionAmount;
};

int Character::getProtectionAmount() { return protectionAmount; };

void Character::anchorHowl() {
  isAnchoring = true;
  useActionPoints(1);
}

bool Character::get_isAnchoring() const { return isAnchoring; };

void Character::resetAnchoring() { isAnchoring = false; }