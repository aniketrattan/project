#ifndef game_h
#define game_h

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace project {

struct GameData{
StateMachine machine;
sf::RenderWindow window;
AssetManager assets;
InputManager input;
};

typedef shared_ptr<GameData> GameDataRef;

class Game{
    private:
    //our frame rate, is currently set to 60 per second
    const float dt = 1.0f/60.0f;
    sf::Clock _clock;

    GameDataRef _data = make_shared<GameData>();
    //function that runs when the game boots up
    void Run();

    public:
    Game(int width, int height, string title);

};

}


#endif