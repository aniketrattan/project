#include "Character.h"

// initializing static variables
int Character::actionPoints = 5;
int Character::money = 0;
bool Character::isProtecting = false;
bool Character::isWeakening = false;

// constructor
Character::Character(int health) {
  this->health = health;
  isAlive = true;
  fire = 0;
  poison = 0;
}

// getters
int Character::get_health() { return health; }
bool Character::get_isAlive() { return isAlive; }
int Character::get_actionPoints() { return actionPoints; }
int Character::get_fire() { return fire; }
int Character::get_poison() { return poison; }
int Character::get_money() { return money; }

// setters
void Character::set_health(int health) {
  if (health > 0) {
    this->health = health;
  } else {
    this->health = 0;
  }
}
void Character::set_actionPoints(int actionPoints) {
  this->actionPoints = actionPoints;
}
void Character::set_fire(int fire) { this->fire = fire; }
void Character::set_poison(int poison) { this->poison = poison; }
void Character::set_money(int money) { this->money = money; }

// updating is alive status if health goes to zero
void Character::checkHealth() {
  if (health <= 0) {
    health = 0;
    isAlive = false;
  } else {
    isAlive = true;
  }
}

// using action points on ability usage
bool Character::useActionPoints(int points) {
  if (actionPoints >= points) {
    actionPoints -= points;
    return true;
  }
  return false; // Insufficient action points
}

// overriding the virtual function
void Character::attack(int damage, Attack &object) {
  int initialHealth = object.get_health();
  int newHealth = initialHealth - damage;
  if (health < 0) {
    health = 0;
  }
  object.set_health(newHealth);
}

// adding item to character inventory
void Character::addItem(const Items &item) { inventory.push_back(item); }

// checking if character has a certain item in their inventory
bool Character::hasItem(const string &itemName) const {
  for (const auto &item : inventory) {
    if (item.get_name() == itemName) {
      return true;
    }
  }
  return false;
}

// removing a certain item from the inventory
bool Character::removeItem(const string &itemName) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (it->get_name() == itemName) {
      inventory.erase(it);
      return true;
    }
  }
  return false;
}

// activating weakening ray
void Character::weakeningRay() {
  isWeakening = true;
  useActionPoints(1);
}

// check if character is using weakening buff
bool Character::get_isWeakening() { return isWeakening; };

// reset the status of weakening ray
void Character::resetWeakening() { isWeakening = false; }

// activating protection buff
void Character::protection() {
  isProtecting = true;
  useActionPoints(1);
}

// check if character is using protection
bool Character::get_isProtecting() { return isProtecting; };

// reset protection status
void Character::resetProtection() { isProtecting = false; }

// setting protection amount
void Character::setProtectionAmount(int protectionAmount) {
  this->protectionAmount = protectionAmount;
};

// getting protection amount
int Character::getProtectionAmount() { return protectionAmount; };

// activating anchor howl buff
void Character::anchorHowl() {
  isAnchoring = true;
  useActionPoints(1);
}

// check if character is using anchor howl buff
bool Character::get_isAnchoring() const { return isAnchoring; };

// reset anchor howl
void Character::resetAnchoring() { isAnchoring = false; }