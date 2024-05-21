#ifndef CLERIC_H
#define CLERIC_H

#include "Character.h"
#include "Fighter.h"
#include "Wizard.h"

class Cleric : public Character {
  protected:
  bool hasHolyWater = false;
public:
  Cleric(int health);
  void equipHolyWater();
  void cleanse(Fighter &fighter, Wizard &wizard);
};

#endif // CLERIC_H