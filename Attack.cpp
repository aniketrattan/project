#include "Attack.h"

void Attack::attack(Character &target,int damage){
  int newHealth=target.get_health()-damage;
  if(newHealth<0){
    newHealth=0; 
  }
  target.set_health(newHealth);
}