#ifndef MINION_H
#define MINION_H

#include "Attack.h"
#include "Character.h"
#include <string>

using namespace std;

class Character;

class Minion : public Attack {
protected:
  string name;
  int health;
  int level;
  bool isAlive;
  int bleed;

public:
  Minion(string name, int health, int level);
  string get_name();
  int get_health();
  void set_health(int health);
  int get_bleed();
  void set_bleed(int bleed);
  int get_level();
  void set_level(int level);
  bool get_isAlive();
  void checkHealth();
  void specialAttack(Character &c1, Character &c2, Character &c3);
  void attack(int damage, Character &c1);
  void attack(int damage, Attack &object);
  void attack(int damage, Character &c1, Character &c2);
  void attack(int damage, Character &c1, Character &c2, Character &c3);
};

#endif // MINION_
