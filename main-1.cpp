#include <iostream>
#include "Boss.h"
#include "Cleric.h"
#include "Fighter.h"
#include "MiniBoss.h"
#include "Minion.h"
#include "Wizard.h"
#include "Attack.h"
using namespace std;


int main() {
   
    Minion minion("MinionA", 50, 1);
    MiniBoss miniBoss("MiniBossA", 100, 2);
    Boss boss("BossA", 200, 3);
    Wizard wizard(100);
    Cleric cleric(80);
    Fighter fighter(120);

   
    wizard.attack(minion, 10);    // Wizard attacks Minion
    cleric.attack(miniBoss, 20);  // Cleric attacks MiniBoss
    fighter.attack(boss, 30);     // Fighter attacks Boss
    boss.attack(wizard, 40);      // Boss attacks Wizard

   
    cout << "Minion's remaining health: " << minion.get_health() <<endl;
    cout << "MiniBoss's remaining health: " << miniBoss.get_health() <<endl;
    cout << "Boss's remaining health: " << boss.get_health() <<endl;
    cout << "Wizard's remaining health: " << wizard.get_health() <<endl;
    return 0;
}