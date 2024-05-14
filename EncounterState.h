#ifndef encounterstate_h
#define encounterstate_h

#include <SFML/Graphics.hpp>
#include "state.h"
#include "Game.h"

namespace project{

class EncounterState : public State{
    private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _fighter;
    sf::Sprite _wizard;
    sf::Sprite _cleric;
    sf::Sprite _encounter;

    public:
    EncounterState(GameDataRef data);

    void Init();

    void handleInput();
    void update( float dt );
    void Draw(float dt);
};


}

#endif