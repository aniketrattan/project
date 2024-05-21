#include "Save.h"
#include "Game.h"
#include "Wizard.h"
#include "Minion.h"

int main() {
    Wizard wizard(150);
    Fighter fighter(30);
    Cleric cleric(135);
    Minion minion("A",50,3);
    MiniBoss miniBoss("B",45,5);

    std::string characterFilename = "characters.txt";
    std::string monsterFilename = "monsters.txt";

    Save saver;

    saver.saveCharacter(wizard, characterFilename);
    saver.saveCharacter(fighter, characterFilename); 
    saver.saveCharacter(cleric, characterFilename);  
    saver.saveMinion(minion, monsterFilename);
    saver.saveMiniBoss(miniBoss, monsterFilename);   
    
    return 0;
}
