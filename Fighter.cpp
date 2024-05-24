#include "Fighter.h"

Fighter::Fighter(int health) : Character(health) {}

// equipping reaper's blade
void Fighter::equipReapersBlade() { hasReapersBlade = true; }

// deals damage and 1 bleed. At the end of the round they take 1 damage from
// each bleed they have
void Fighter::serratedSlash(Minion &target) {
  int damage = 20;

  // increase damage and bleed amount if reaper's blade is equipped
  if (hasReapersBlade) {
    damage += 5;
    bleedAmount += 2;
  }
  target.set_bleed(target.get_bleed() + bleedAmount);
  attack(damage, target);
  useActionPoints(1);
}
