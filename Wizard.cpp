#include "Wizard.h"

Wizard::Wizard(int health) : Character(health) {}

void Wizard::equipRingOfFire() { hasRingOfFire = true; }

// massive damage attack
void Wizard::fireball(Minion &target) {
  int damage = 30;

  // increase damage if ring of fire equipped
  if (hasRingOfFire) {
    damage += 10; // Increase damage by 10
  }
  attack(damage, target);
  useActionPoints(1);
}
