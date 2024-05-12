#include <iostream>
#include "MiniBoss.h"
#include "Character.h"

#include <string>
using namespace std;

MiniBoss::MiniBoss():Minion(" ",0,0){
    
}
MiniBoss::MiniBoss(string name,int health,int level):Minion(name,health,level){

}
void MiniBoss::attack(int damage,Character &target){
    target.set_health(target.get_health()-damage);
    cout<<"The damage by minion is:"<<damage<<endl;
}