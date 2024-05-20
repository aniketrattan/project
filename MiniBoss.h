#ifndef MINIBOSS_H
#define MINIBOSS_H

#include "Minion.h"
#include "Character.h"

class MiniBoss : public Minion {
    public:
    MiniBoss (string name, int health, int level);
    void specialAttack (Character &c1, Character &c2, Character &c3);
};

#endif // MINIBOSS_H