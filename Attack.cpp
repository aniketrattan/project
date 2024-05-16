#include "Attack.h"

<<<<<<< HEAD
void Attack::attack(Attack& object,int damage){

}
void Attack::set_health(int health){

}
int Attack::get_health(){
  
=======
void Attack::attack(Character &target,int damage){
  int newHealth=target.get_health()-damage;
  if(newHealth<0){
    newHealth=0; 
  }
  target.set_health(newHealth);
>>>>>>> fc5b9bc5f14da4ce3a21c54450cf28f4acb51457
}