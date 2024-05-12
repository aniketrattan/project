#ifndef MINIBOSS_H
#define MINIBOSS_H
#include "Minion.h"

class MiniBoss:public Minion{
    public:
    MiniBoss();
    MiniBoss(string name,int health,int level);
    void attack(int damage,Character &target);
};


#endif