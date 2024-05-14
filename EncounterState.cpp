#include <sstream>
#include "EncounterState.h"
#include "Definitions.h"

namespace project{

EncounterState::EncounterState(GameDataRef data) : _data(data) {}

//initialize function
void EncounterState::Init() {
    //load background
    _data->assets.LoadTexture("Encounter Background",ENCOUNTER_BACKGROUND_FILEPATH);
    //load charatcer sprites
    _data->assets.LoadTexture("Fighter",FIGHTER_SPRITE_FILEPATH);
    _data->assets.LoadTexture("Wizard",WIZARD_SPRITE_FILEPATH);
    _data->assets.LoadTexture("Cleric",CLERIC_SPRITE_FILEPATH);
    //load monster sprite
    _data->assets.LoadTexture("Encounter",SLIME_SPRITE_FILEPATH);
    
    //set png to there respective data member
    _background.setTexture(this->_data->assets.GetTexture("Encounter Background"));
    _fighter.setTexture(this->_data->assets.GetTexture("Fighter"));
    _wizard.setTexture(this->_data->assets.GetTexture("Wizard"));
    _cleric.setTexture(this->_data->assets.GetTexture("Cleric"));
    _encounter.setTexture(this->_data->assets.GetTexture("Encounter"));

    //setting position of each sprite
    _fighter.setPosition( (SCREEN_HEIGHT-100) - (_fighter.getGlobalBounds().width / 2) , _fighter.getGlobalBounds().height / 2 + 140);
    _wizard.setPosition( ( SCREEN_HEIGHT / 2) - (_wizard.getGlobalBounds().width / 2) , _wizard.getGlobalBounds().height / 2 + 140);
    _cleric.setPosition( (SCREEN_HEIGHT / 4) - (_cleric.getGlobalBounds().width / 2), _cleric.getGlobalBounds().height / 2 + 140);
    _encounter.setPosition( (5*SCREEN_HEIGHT/4) , _encounter.getGlobalBounds().height / 2 + 140);
}
void EncounterState::handleInput() {

    sf::Event event;

    while(_data->window.pollEvent(event)){
        if( sf::Event::Closed == event.type){
            _data->window.close();
        }
    }

}

void EncounterState::update(float dt) {
    
}

void EncounterState::Draw(float dt) {
    //clears the window
    _data->window.clear();
    //adds all the sprites to the window
    _data->window.draw(_background);
    _data->window.draw(_fighter);
    _data->window.draw(_wizard);
    _data->window.draw(_cleric);
    _data->window.draw(_encounter);
    //dispalys the sprites
    _data->window.display();
}
}  // namespace project