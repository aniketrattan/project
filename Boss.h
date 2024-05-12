#ifndef BOSS_H
#define BOSS_H
#include "Minion.h"

class Boss:public Minion{
    public:
    Boss();
    Boss(string name,int health,int level);
    void attack(int damage,Character &target);
};


#endif