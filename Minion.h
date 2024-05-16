#ifndef MINION_H
#define MINION_H

#include <string>
<<<<<<< HEAD
#include "Attack.h"
#include "Character.h"

using namespace std;


class Character;

class Minion:public Attack {
=======
using namespace std;

#include "Character.h"
#include "Attack.h"

class Minion {
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
protected:
  string name;
  int health;
  int level;
<<<<<<< HEAD
  bool isAlive;
  int bleed;
=======
  void weaponDrop();
  bool isAlive;
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457

public:
  Minion(string name, int health, int level);
  string get_name();
  int get_health();
  void set_health(int health);
<<<<<<< HEAD
  int get_bleed();
  void set_bleed(int bleed);
  int get_level();
  void set_level(int level);
  bool get_isAlive();
  void checkHealth();
  void attacker(int damage, Character &c1);
  void attacker(int damage, Character &c1, Character &c2);
  void attacker(int damage, Character &c1, Character &c2, Character &c3);
  void attack(Attack& object,int damage);

};

#endif // MINION_



  
=======
  int get_level();
  bool get_isAlive();

  void attack(Character &target,int damage);
};

#endif 
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
