#ifndef CHARACTER_H
#define CHARACTER_H

#include "Attack.h"
#include "Items.h"
#include "Minion.h"
#include <string>
#include <vector>

using namespace std;

class Character : public Attack {
protected:
  int health;
  bool isAlive;
  static int actionPoints;
  static int money;

  // buffs and debuffs
  int fire;
  int poison;
  int protectionAmount = 5;
  static bool isWeakening;
  static bool isProtecting;
  bool isAnchoring;

  // vector for holding character items
  vector<Items> inventory;

public:
  // constructor
  Character(int health);

  // getters
  int get_health();
  bool get_isAlive();
  int get_actionPoints();
  int get_fire();
  int get_poison();
  int get_money();

  // setters
  void set_health(int health);
  void set_actionPoints(int actionPoints);
  void set_fire(int fire);
  void set_poison(int poison);
  void set_money(int money);

  // update is alive status
  void checkHealth();

  // use action points on abilities
  bool useActionPoints(int points);

  // weakening ray
  void weakeningRay();
  bool get_isWeakening();
  void resetWeakening();

  // protection
  void protection();
  bool get_isProtecting();
  void resetProtection();
  void setProtectionAmount(int protectionAmount);
  int getProtectionAmount();

  // anchor howl
  void anchorHowl();
  bool get_isAnchoring() const;
  void resetAnchoring();

  // inventory management
  void addItem(const Items &item);
  bool hasItem(const string &itemName) const;
  bool removeItem(const string &itemName);

  // attack function
  void attack(int damage, Attack &object);
};

#endif // CHARACTER_H