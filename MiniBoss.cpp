#include "MiniBoss.h"

// constructor
MiniBoss::MiniBoss(string name, int health, int level)
    : Minion(name, health, level) {
  srand(time(nullptr));
};

// attack
void MiniBoss::specialAttack(Character &c1, Character &c2, Character &c3) {
  // Generate a random number between 0 and 99
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
    // random damage between 25 and 35
    int damage = rand() % 11 + 25;
    cout << damage << endl;

    // if any buff/debuff is active, alter the damage accordingly
    if (c1.get_isAnchoring() || c2.get_isAnchoring() || c3.get_isAnchoring()) {
      attack(damage, c1);
    } 
    if (c1.get_isWeakening() || c2.get_isWeakening() || c3.get_isWeakening()) {
        attack((damage / 2), *targets[index1], *targets[index2]);
    } 
    if (c1.get_isProtecting() || c2.get_isProtecting() || c3.get_isProtecting()) {
          attack((damage - c1.getProtectionAmount()), *targets[index1], *targets[index2]);
    } 
    else {
      attack(damage, *targets[index1], *targets[index2]);
    }

  } else {
    Character *newtargets[3] = {&c1, &c2, &c3};
    int index3 = rand() % 3;
    int index4;
    do {
      index4 = rand() % 3;
    } while (index4 == index3);
    // random damage between 25 and 35
    int damage = rand() % 11 + 25;
    cout << damage << endl;
    if (c1.get_isProtecting() || c2.get_isProtecting() || c3.get_isProtecting()) {
          attack((damage - c1.getProtectionAmount()), *newtargets[index3], *newtargets[index4]);
    } else {
    attack(damage, *newtargets[index3], *newtargets[index4]);
    }
  }
}
