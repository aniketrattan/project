#include "MiniBoss.h"
#include <ctime>

MiniBoss::MiniBoss(string name, int health, int level)
    : Minion(name, health, level) {
  srand(time(nullptr));
};

void MiniBoss::specialAttack(Character &c1, Character &c2, Character &c3) {

  int chance = rand() % 100;
  if (chance < 40) { // 40% chance
    // Choose two random characters out of c1, c2, and c3
    Character *targets[3] = {&c1, &c2, &c3};
    int index1 = rand() % 3;
    int index2;
    do {
      index2 = rand() % 3;
    } while (index2 == index1);

    // Randomly select between fire and poison attack
    int attackType = rand() % 2; // 0 for fire, 1 for poison

    if (attackType == 0) { // Fire attack
      targets[index1]->set_fire(targets[index1]->get_fire() + 1);
      targets[index2]->set_fire(targets[index2]->get_fire() + 1);
    } else { // Poison attack
      targets[index1]->set_poison(targets[index1]->get_poison() + 1);
      targets[index2]->set_poison(targets[index2]->get_poison() + 1);
    }
    int damage = rand() % 11 + 25;
    attack(damage, c1, c2);

  } else {
    int damage = rand() % 11 + 25;
    attack(damage, c1, c2);
  }
}