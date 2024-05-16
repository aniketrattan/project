#ifndef ATTACK_H
#define ATTACK_H


<<<<<<< HEAD
class Attack{
    protected:
    int health;
    public:
    virtual~Attack()=default;

    virtual void set_health(int health)=0;
    virtual int get_health()=0;
    virtual void attack(Attack& object,int damage)=0;
};

#endif






=======
#include "Character.h"

class Character;

class Attack{
    public:
    virtual void attack(Character &character,int damage)=0;
};

#endif
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
