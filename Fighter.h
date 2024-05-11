#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"

class Fighter : public Character {
public:
  Fighter(int health);
  void serratedSlash();
};

#endif // FIGHTER_H