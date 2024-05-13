#ifndef BOSS_H
#define BOSS_H
#include "Minion.h"
#include "Attack.h"

class Boss:public Minion{
    public:
    Boss();
    Boss(string name,int health,int level);
    void attack(Character &target,int damage);
};


#endif