#ifndef MINION_H
#define MINION_H

#include "Attack.h"
#include "Character.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Forward declaration of character class
class Character;

class Minion : public Attack {
protected:
  string name;
  int health;
  int level;
  bool isAlive;

public:
  // constructor
  Minion();
  Minion(string name, int health, int level);

  // getters
  string get_name();
  int get_health();
  int get_level();
  bool get_isAlive();

  // setters
  void set_health(int health);
  void set_level(int level);

  // updating alive status
  void checkHealth();

  // attacks
  void attack(int damage, Character &c1);
  void attack(int damage, Attack &object);
};

#endif // MINION_
