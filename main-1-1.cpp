#include <iostream>
#include "Minion.h"
#include "MiniBoss.h"
#include "Boss.h"
#include "Character.h" 
#include "Attack.h"

using namespace std;

int main() {

    Character player(100);
    Minion minion("Minion",50,3);
    MiniBoss miniBoss("Mini Boss",150,8);
    Boss boss("Boss",500,10);

    minion.attack(player,20);
    miniBoss.attack(player,30);
    boss.attack(player,100);

    cout<<"Player's health is:"<<player.get_health()<<endl;

    return 0;  
}
