#include "Fighter.h"

Fighter::Fighter(int health) : Character(health) {}

void Fighter::equipReapersBlade() {
    hasReapersBlade = true;
}

// deals damage and 1 bleed. At the end of the round they take 1 damage from
// each bleed they have
void Fighter::serratedSlash(Minion &target) {
  int damage = 20;
  if (hasReapersBlade) {
    damage += 5;
    bleedAmount += 2;
  }
  target.set_bleed(target.get_bleed() + bleedAmount); 
  attack(damage, target);
  useActionPoints(1);
}

// stops a charge up attack
void Fighter::stunningStrike() { useActionPoints(1); }