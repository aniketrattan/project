#ifndef ATTACK_H
#define ATTACK_H

class Attack {
protected:
  int health;

public:
  virtual ~Attack() = default;

  virtual void set_health(int health) = 0;
  virtual int get_health() = 0;
  virtual void attack(int damage, Attack &object ) = 0;
};

#endif