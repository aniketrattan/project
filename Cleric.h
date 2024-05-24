#ifndef CLERIC_H
#define CLERIC_H

#include "Character.h"
#include "Fighter.h"
#include "Wizard.h"

class Cleric : public Character {
protected:
  bool hasHolyWater = false;

public:
  // constructor
  Cleric(int health);

  // equip item
  void equipHolyWater();

  // cleanse ability
  void cleanse(Fighter &fighter, Wizard &wizard);
};

#endif // CLERIC_H