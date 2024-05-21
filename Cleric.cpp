#include "Cleric.h"

Cleric::Cleric(int health) : Character(health) {}

void Cleric::equipHolyWater() {
    hasHolyWater = true;
}

//removes 1 effect off of character i.e burn or poison effect.
void Cleric::cleanse(Fighter &fighter, Wizard &wizard) {
    fighter.set_fire(0);
    wizard.set_poison(0);
    useActionPoints(1);
}