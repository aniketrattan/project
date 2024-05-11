#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"

class Wizard : public Character {
public:
  Wizard(int health);
  void fireball();
  void weakeningRay();
};

#endif // FIGHTER_H