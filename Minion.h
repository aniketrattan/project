#ifndef MINION_H
#define MINION_H

#include <string>
using namespace std;

#include "Character.h"

class Minion {
protected:
  string name;
  int health;
  int level;
  void weaponDrop();
  bool isAlive;

public:
  Minion(string name, int health, int level);
  string get_name();
  int get_health();
  void set_health(int health);
  int get_level();
  bool get_isAlive();
  virtual void attack(int damage,Character &character)=0;
};

#endif 