#ifndef game_h
#define game_h

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "AssetManager.h"
#include "Game.h"
#include "Shop.h"
#include "StateMachine.h"

namespace graphics {

struct GameData {
  StateMachine machine;
  sf::RenderWindow window;
  AssetManager assets;
};

typedef shared_ptr<GameData> GameDataRef;

class GameGraphic{
 private:
  // our frame rate, is currently set to 60 per second
  const float dt = 1.0f / 60.0f;
  sf::Clock _clock;

  GameDataRef _data = make_shared<GameData>();
  // function that runs when the game boots up
  void Run();

 public:
 

  GameGraphic(int width, int height, string title);
};

}  // namespace graphics

#endif