#ifndef GAME_H
#define GAME_H

#include "Fighter.h"
#include "Wizard.h"
#include "Cleric.h"

class Game {
private:
    Fighter* fighter;
    Wizard* wizard;
    Cleric* cleric;

public:
    Game();
    void initializeGame(); // Declaration of the initializeGame function
    void checkEndCondition(); // Declaration of the checkEndCondition function
};

#endif // GAME_H
