#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;
<<<<<<< HEAD

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
=======
#include "Attack.h"
class Minion;

class Character {
protected:

  int health;
  string equippedWeapon;
  bool isAlive;
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457

public:
  Character(int health);
  int get_health();
  void set_health(int health);
  bool get_isAlive();
<<<<<<< HEAD
  void checkHealth();
  int get_actionPoints();
  bool useActionPoints(int points);
  void set_fire(int fire);
  int get_fire();
  void set_poison(int poison);
  int get_poison();

  void attack(Attack& object,int damage);
  
=======
  void attack(int damage, Minion &target);
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
};

#endif // CHARACTER_H