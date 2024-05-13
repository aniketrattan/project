#include <iostream>
#include "Boss.h"
#include <string>
using namespace std;

Boss::Boss():Minion(" ",0,0){
    
}
Boss::Boss(string name,int health,int level):Minion(name,health,level){

}
void Boss::attack(Character &target,int damage){
    int actualDamage=damage*2;
    target.set_health(target.get_health()-actualDamage);
    int newHealth=target.get_health()-damage;
    if(newHealth<0){
        newHealth=0;
    }
    target.set_health(newHealth);
    cout<<"The damage by boss is:"<<actualDamage<<endl;
}