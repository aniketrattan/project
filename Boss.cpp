#include <iostream>
#include "Boss.h"
#include <string>
using namespace std;

Boss::Boss():Minion(" ",0,0){
    
}
Boss::Boss(string name,int health,int level):Minion(name,health,level){

}
void Boss::attack(int damage,Character &target){
    int actualDamage=damage*2;
    target.set_health(target.get_health()-actualDamage);
    cout<<"The damage by boss is:"<<actualDamage<<endl;
}