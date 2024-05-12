#include <iostream>
#include "Minion.h"
#include "MiniBoss.h"
#include "Boss.h"
#include "Character.h" 

int main() {
   
    MiniBoss B("MonstorA", 500, 10);
    Boss C("MonostorB",750,15);
    Character player1(1000);
    Character player2(1000);
    Minion *miniboss = &B;
    Minion *boss=&C;
    int damage = 100;
    miniboss->attack(damage, player1); 
    cout << "The player's health is: " << player1.get_health()<< endl;

    damage=300;
    boss->attack(damage,player2);
    cout<<"The player's health is:"<<player2.get_health()<<endl;
    return 0;
}
