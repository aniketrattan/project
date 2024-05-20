#include "Boss.h"

Boss::Boss(string name, int health, int level) : Minion(name, health, level) {
  srand(time(nullptr));
};

void Boss::specialAttack(Character &c1, Character &c2, Character &c3) {

  // Regular attack
  attack(40, c1, c2);

  // Generate a random number between 0 and 99
  int chance = rand() % 100;
  if (chance < 75) { // 75% chance
    // Choose three random characters out of c1, c2, and c3
    Character *targets[3] = {&c1, &c2, &c3};
    int indexes[3];
    for (int i = 0; i < 3; ++i) {
      int index;
      do {
        index = rand() % 3;
      } while (i > 0 && index == indexes[0] ||
               (i > 1 && (index == indexes[1] || index == indexes[0])));
      indexes[i] = index;
    }

    // Randomly select between fire and poison attack
    int attackType = rand() % 2; // 0 for fire, 1 for poison

    if (attackType == 0) { // Fire attack
      for (int i = 0; i < 3; ++i) {
        targets[indexes[i]]->set_fire(targets[indexes[i]]->get_fire() + 2);
      }
    } else { // Poison attack
      for (int i = 0; i < 3; ++i) {
        targets[indexes[i]]->set_poison(targets[indexes[i]]->get_poison() + 2);
      }
    }
  } else {
    attack(30, c1, c2, c3);
  }
}