#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

#include "Attack.h"
#include "Items.h"
#include "Minion.h"
#include <vector>

class Character : public Attack {
protected:
  int health;
  bool isAlive;
  static int actionPoints;
  int fire;
  int poison;
  static int money;
  int protectionAmount = 5;
  static bool isWeakening;
  static bool isProtecting;
  vector<Items> inventory;
  bool isAnchoring;

public:
  Character(int health);
  int get_health();
  void set_health(int health);
  bool get_isAlive();
  void checkHealth();
  int get_actionPoints();
  void set_actionPoints(int actionPoints);
  bool useActionPoints(int points);
  void set_fire(int fire);
  int get_fire();
  void set_poison(int poison);
  int get_poison();
  void weakeningRay();
  bool get_isWeakening();
  void resetWeakening();
  void protection();
  bool get_isProtecting();
  void resetProtection();
  void setProtectionAmount(int protectionAmount);
  int getProtectionAmount();
  void anchorHowl();
  bool get_isAnchoring() const;
  void resetAnchoring();
  int get_money(); // Get money
  void set_money(int money);
  void addItem(const Items &item);
  bool hasItem(
      const string &itemName) const; // Method to check for an item in inventory
  bool removeItem(const string &itemName);
  void attack(int damage, Attack &object);
};

#endif // CHARACTER_H