#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

#include "Attack.h"
#include "Minion.h"

class Character : public Attack {
protected:
  int health;
  string equippedWeapon;
  bool isAlive;
  static int actionPoints;
  bool isBlocking;
  int fire;
  int poison;

public:
  Character(int health);
  int get_health();
  void set_health(int health);
  bool get_isAlive();
  bool checkHealth();
  int get_actionPoints();
  bool useActionPoints(int points);
  void set_fire(int fire);
  int get_fire();
  void set_poison(int poison);
  int get_poison();
  void block();          // Add the block function
  bool get_isBlocking(); // Add a getter for isBlocking
  void resetBlock();     // Add a function to reset blocking status

  void attack(int damage, Attack &object);
};

#endif // CHARACTER_H