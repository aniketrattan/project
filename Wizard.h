#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include "Minion.h"

class Wizard : public Character {
  protected:
  bool hasRingOfFire;
public:
  Wizard(int health);
  void equipRingOfFire();
  void fireball(Minion &target);
  bool isProtecting = false;
};

#endif // WIZARD_H