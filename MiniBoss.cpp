#include <iostream>
#include "MiniBoss.h"
#include "Character.h"

#include <string>
using namespace std;

MiniBoss::MiniBoss():Minion(" ",0,0){
    
}
MiniBoss::MiniBoss(string name,int health,int level):Minion(name,health,level){

}
void MiniBoss::attack(Character &target,int damage){
    target.set_health(target.get_health()-damage);
    int newHealth=target.get_health()-damage;
    if(newHealth<0){
        newHealth=0; 
    }
    target.set_health(newHealth);
    cout<<"The damage by minion is:"<<damage<<endl;
}