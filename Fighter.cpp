#include <iostream>
#include "Fighter.h"
using namespace std;

Fighter::Fighter(int health):Character(health){
    set_health(health);
}
// deals damage and 1 bleed. At the end of the round they take 1 damage from
// each bleed they have
void Fighter::serratedSlash(Minion &target) {
  target.set_bleed(target.get_bleed() + 1);
  useActionPoints(1);
}

// stops a charge up attack
void Fighter::stunningStrike() { useActionPoints(1); }


void Fighter::attack(Attack& object,int damage) {
  int initialHealth=object.get_health();;
  int newHealth=initialHealth-damage;
  object.set_health(newHealth);
  cout<<"The damage by Fighter is:"<<damage<<endl;
}