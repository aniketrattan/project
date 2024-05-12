#include <iostream>
#include "Boss.h"
#include <string>
using namespace std;

Boss::Boss():Minion(" ",0,0){
    
}
Boss::Boss(string name,int health,int level):Minion(name,health,level){

}
void Boss::attack(){
    cout<<"Boss attacks!!";
}