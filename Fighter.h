#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
#include "Minion.h"

class Fighter : public Character {
public:
  Fighter(int health);
  void serratedSlash(Minion &target);
  void stunningStrike();
};

#endif // FIGHTER_H