#ifndef MINIBOSS_H
#define MINIBOSS_H
#include "Minion.h"
#include "Attack.h"

class MiniBoss:public Minion{
    public:
    MiniBoss();
    MiniBoss(string name,int health,int level);
    void attack(Character &target,int damage);
};


#endif