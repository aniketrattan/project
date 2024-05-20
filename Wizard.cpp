#include "Wizard.h"

Wizard::Wizard(int health) : Character(health) {}
//spends one round charging attack then hit all enemies with damage
void Wizard::fireball(Minion &target) {
    attack(30, target);
    useActionPoints(1);
}

