#ifndef ATTACK_H
#define ATTACK_H


#include "Character.h"

class Character;

class Attack{
    public:
    virtual void attack(Character &character,int damage)=0;
};

#endif