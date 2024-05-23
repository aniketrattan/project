#ifndef BOSS_H
#define BOSS_H

#include "Minion.h"

class Boss : public Minion {
public:
  // constructor
  Boss(string name, int health, int level);

  // attack
  void specialAttack(Character &c1, Character &c2, Character &c3);
};

#endif // BOSS_H
