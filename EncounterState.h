#ifndef encounterstate_h
#define encounterstate_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "state.h"
#include "GameGraphic.h"
#include "NumDisplay.h"
#include "MenuDisplay.h"

namespace graphics{

class EncounterState : public State{
    private:
    GameDataRef _data;
    //sprites
    sf::Sprite _background;
    sf::Sprite _fighter;
    sf::Sprite _wizard;
    sf::Sprite _cleric;
    sf::Sprite _encounter;
    //number displays for sprites
    NumDisplay* _fighterNum;
    NumDisplay* _wizardNum;
    NumDisplay* _clericNum;
    NumDisplay* _encounterNum;
    //display for menus
    MenuDisplay* _menuEncounter;
    //will lock menu when in one
    int menuLock;
    //what values will be shown from the menus vector 
    int menuBeginning;
    int menuEnd;
    //menu
    vector<string> menus = {"1) Fighter actions", "2) Wizard actions", "3) Cleric actions", "0) End round", "4) Serrated Slash",
    "5) Stunning Strike", "6) Fireball", "7) Weaking Ray", "8) Protection", "9) Cleanse"};
    //number refresh counter
    int triggerNum;
    // need to add a variable in the round function that says what round it is

    public:
    EncounterState(GameDataRef data);

    void Init();

    void handleInput();
    void update( float dt );
    void Draw(float dt);
};


}

#endif