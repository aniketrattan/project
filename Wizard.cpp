#include <iostream>
#include "Wizard.h"
using namespace std;

Wizard::Wizard(int health) : Character(health) {}
//spends one round charging attack then hit all enemies with damage
void Wizard::fireball() {
    useActionPoints(1);
}

//chooses one enemie, there damage reduction is reduced down to the previous level for x rounds
void Wizard::weakeningRay(Minion &target) {
    target.set_level(target.get_level() - 1);
    useActionPoints(1);
}

void Wizard::attack(Attack& object,int damage) {
    int initialHealth=object.get_health();;
    int newHealth=initialHealth-damage;
    if(health<0){
      health=0;
    }
    object.set_health(newHealth);
}
    
