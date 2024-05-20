#ifndef BOSS_H
#define BOSS_H

#include "Character.h"
#include "Minion.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()


class Boss : public Minion {
public:
  Boss(string name, int health, int level);
  void specialAttack(Character &c1, Character &c2, Character &c3);
};

#endif // BOSS_H
