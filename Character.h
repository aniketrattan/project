#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

#include "Attack.h"
#include "Minion.h"

class Character:public Attack{
protected:
  int health;
  string equippedWeapon;
  bool isAlive;
  static int actionPoints;
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

  void attack(Attack& object,int damage);
  
};

#endif // CHARACTER_H