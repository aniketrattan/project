#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Minion;

class Character {
protected:

  int health;
  string equippedWeapon;
  bool isAlive;

public:
  Character(int health);
  int get_health();
  void set_health(int health);
  bool get_isAlive();
  void attack(int damage, Minion &target);
};

#endif // CHARACTER_H