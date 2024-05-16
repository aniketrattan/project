#include <iostream>
#include "Cleric.h"
using namespace std;

Cleric::Cleric(int health):Character(health){
    set_health(health);
}

// give an amount of block to all characters i.e if block is 10 points of mitigation then thia gives 3 points to each character 
void Cleric::protection() {
    useActionPoints(1);
}

//removes 1 effect off of character i.e burn or poison effect.
void Cleric::cleanse() {
    useActionPoints(1);
}

void Cleric::attack(Attack& object,int damage) {
  int initialHealth=object.get_health();;
  int newHealth=initialHealth-damage;
  if(newHealth<0){
    newHealth=0;
  }
  object.set_health(newHealth);
  cout<<"The damage by Cleric is:"<<damage<<endl;
}
    
