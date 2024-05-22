#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"

class Fighter : public Character {
protected:
  bool hasReapersBlade;
  int bleedAmount = 1;

public:
  // constructor
  Fighter(int health);

  // equip item
  void equipReapersBlade();

  // attack
  void serratedSlash(Minion &target);
};

#endif // FIGHTER_H