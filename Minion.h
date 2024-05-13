#ifndef MINION_H
#define MINION_H

#include <string>
using namespace std;

class Character;

class Minion {
protected:
  string name;
  int health;
  int level;
  void weaponDrop();
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
  void attack(int damage, Character &character);
  void checkHealth();
};

#endif // MINION_H
