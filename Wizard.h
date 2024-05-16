#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include "Attack.h"
#include "Minion.h"


class Wizard : public Character{

public:
  Wizard(int health);
  void fireball();
  void weakeningRay(Minion &target);

  void attack(Attack& object,int damage);

};

#endif 



