#include <iostream>
#include "Wizard.h"
using namespace std;

int main(){

    Wizard wiz(40);
   
    cout<<"Is the charcacter alive?" <<wiz.checkHealth()<<endl;

    Minion minion("MinionA", 50, 1);
    minion.attack(wiz,60);

    wiz.attack(minion,100);
    cout<<"Health of minion:"<<minion.get_health()<<endl;
    

    cout << "Wizard's remaining health: " << wiz.get_health()<<endl;

    cout<<"Is the character alive?"<<wiz.checkHealth()<<endl;
    return 0;
}