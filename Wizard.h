#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include "Minion.h"

class Wizard : public Character {
public:
  Wizard(int health);
  void fireball();
  void weakeningRay(Minion &target);
};

#endif // FIGHTER_H