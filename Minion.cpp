#include <iostream>
#include "Minion.h"

#include <string>
using namespace std;

Minion::Minion(string name, int health, int level) {
  this->name = name;
  this->health = health;
  this->level = level;
  isAlive = true;
  bleed = 0;
}

string Minion::get_name() { return name; }

int Minion::get_health() { return health; }

int Minion::get_level() { return level; }

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

    
