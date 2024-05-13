#include "Fighter.h"

Fighter::Fighter(int health) : Character(health) {}

//deals damage and 1 bleed. At the end of the round they take 1 damage from each bleed they have
void Fighter::serratedSlash(Minion &target) {
    target.set_bleed(target.get_bleed() + 1);
}

//stops a charge up attack
void Fighter::stunningStrike() {}