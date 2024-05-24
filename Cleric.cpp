#include "Cleric.h"

Cleric::Cleric(int health) : Character(health) {}

// equip holy water item
void Cleric::equipHolyWater() { hasHolyWater = true; }

// removes burn or poison effect.
void Cleric::cleanse(Fighter &fighter, Wizard &wizard) {
  fighter.set_fire(0);
  wizard.set_poison(0);
  useActionPoints(1);
}