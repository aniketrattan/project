#ifndef CLERIC_H
#define CLERIC_H

#include "Character.h"

class Cleric : public Character {
public:
  Cleric(int health);
  void protection();
  void cleanse();
};

#endif // CLERIC_H