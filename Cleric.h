#ifndef CLERIC_H
#define CLERIC_H

#include "Character.h"
#include "Fighter.h"
#include "Wizard.h"

class Cleric : public Character {
public:
  Cleric(int health);
  void protection();
  void cleanse(Fighter &fighter, Wizard &wizard);
};

#endif // CLERIC_H