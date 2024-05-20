#include "Wizard.h"

Wizard::Wizard(int health) : Character(health) {}

void Wizard::equipRingOfFire() {
    hasRingOfFire = true;
}

//spends one round charging attack then hit all enemies with damage
void Wizard::fireball(Minion &target) {
    int damage = 30;
    if (hasRingOfFire) {
        damage += 10; // Increase damage by 10
    }
    attack(damage, target);
    useActionPoints(1);
}

