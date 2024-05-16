#ifndef ATTACK_H
#define ATTACK_H


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






