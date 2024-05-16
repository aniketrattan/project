#include <iostream>
#include "Minion.h"
<<<<<<< HEAD

#include <string>
using namespace std;

=======
#include "Attack.h"
#include <string>
using namespace std;


>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
Minion::Minion(string name, int health, int level) {
  this->name = name;
  this->health = health;
  this->level = level;
  isAlive = true;
<<<<<<< HEAD
  bleed = 0;
=======
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
}

string Minion::get_name() { return name; }

int Minion::get_health() { return health; }

int Minion::get_level() { return level; }

<<<<<<< HEAD
void Minion::set_level(int level) { this->level = level; }

int Minion::get_bleed() { return bleed; }

void Minion::set_bleed(int bleed) { this->bleed = bleed; }

bool Minion::get_isAlive() { return isAlive; }

void Minion::set_health(int health) { this->health = health;}
void Minion::attacker(int damage, Character &target) {
  target.set_health(target.get_health() - damage);
}

void Minion::attacker(int damage, Character &c1, Character &c2) {
  c1.set_health(c1.get_health() - damage);
  c2.set_health(c2.get_health() - damage);
}

void Minion::attacker(int damage, Character &c1, Character &c2, Character &c3) {
  c1.set_health(c1.get_health() - damage);
  c2.set_health(c2.get_health() - damage);
  c3.set_health(c3.get_health() - damage);
}

void Minion::checkHealth() {
  if (health <= 0) {
    isAlive = false;
  }
}

void Minion::attack(Attack& object,int damage){
    int initialHealth=object.get_health();;
    int newHealth=initialHealth-damage;
    if(newHealth<0){
        newHealth=0;
    }
    object.set_health(newHealth);
    cout<<"The damage by minion is:"<<damage<<endl;
}

    
=======
bool Minion::get_isAlive() { return isAlive; }

void Minion::set_health(int health) { this->health = health; }

void Minion::attack(Character &target,int damage){
  int newHealth=target.get_health()-damage;
  if(newHealth<0){
    newHealth=0; 
  }
  target.set_health(newHealth);
  cout<<"The damage done by minion is:"<<damage<<endl;
}
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
