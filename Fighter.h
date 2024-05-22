#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
#include "Minion.h"

class Fighter : public Character {
protected:
  bool hasReapersBlade;
  int bleedAmount = 1;

public:
  Fighter(int health);
  void equipReapersBlade();
  void serratedSlash(Minion &target);
};

#endif // FIGHTER_H