#include <iostream>
#include "MiniBoss.h"
#include <string>
using namespace std;

MiniBoss::MiniBoss():Minion(" ",0,0){
    
}
MiniBoss::MiniBoss(string name,int health,int level):Minion(name,health,level){

}
void MiniBoss::attack(){
    cout<<"MiniBoss attacks!!";
}