#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

class Wizard : public Character {
protected:
  bool hasRingOfFire;

public:
  // constructor
  Wizard(int health);

  // equip item
  void equipRingOfFire();

  void fireball(Minion &target);
  bool isProtecting = false;
};

#endif // FIGHTER_H