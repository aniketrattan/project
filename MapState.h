#ifndef mapstate_h
#define mapstate_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "GameGraphic.h"
#include "MenuDisplay.h"
#include "state.h"

namespace graphics {

class MapState : public State {
 private:
  GameDataRef _data;
  // sprites
  sf::Sprite _background;

  MenuDisplay* _menuPaths;

  // what values will be shown from the paths vector
  int menuBeginning;
  int menuEnd;

  vector<string> paths = { "left) campsite", "up) encounter", "right) shop"};

 public:
  MapState(GameDataRef data);

  void Init();

  void handleInput();
  void update(float dt);
  void Draw(float dt);


};

}  // namespace graphics

#endif