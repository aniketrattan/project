#ifndef BOSS_H
#define BOSS_H
<<<<<<< HEAD

#include "Character.h"
#include "Minion.h"
#include "Attack.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()


class Boss : public Minion {
public:
  Boss(string name, int health, int level);
  void specialAttack(Character &c1, Character &c2, Character &c3);
  void attack(Attack& object,int damage);

};

#endif // BOSS_H


=======
#include "Minion.h"
#include "Attack.h"

class Boss:public Minion{
    public:
    Boss();
    Boss(string name,int health,int level);
    void attack(Character &target,int damage);
};


#endif
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
