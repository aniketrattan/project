#ifndef MINIBOSS_H
#define MINIBOSS_H

#include "Minion.h"
#include "Character.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class MiniBoss : public Minion {
    public:
    MiniBoss (string name, int health, int level);
    void specialAttack (Character &c1, Character &c2, Character &c3);
};

#endif // MINIBOSS_H