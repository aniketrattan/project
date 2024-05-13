#include "Wizard.h"

Wizard::Wizard(int health) : Character(health) {}
//spends one round charging attack then hit all enemies with damage
void Wizard::fireball() {}
//chooses one enemie, there damage reduction is reduced down to the previous level for x rounds
void Wizard::weakeningRay(Minion &target) {
    target.set_level(target.get_level() - 1);
}