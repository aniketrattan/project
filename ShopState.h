#ifndef shopstate_h
#define shopstate_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "GameGraphic.h"
#include "MenuDisplay.h"
#include "state.h"

namespace graphics {

class ShopState : public State {
 private:
  GameDataRef _data;
  // sprites
  sf::Sprite _background;

  MenuDisplay* _menuItems;

  // what values will be shown from the paths vector
  int menuBeginning;
  int menuEnd;

  vector<string> items = {"1) sword", "2) wand", "3) holy water"};

 public:
  ShopState(GameDataRef data);

  void Init();

  void handleInput();
  void update(float dt);
  void Draw(float dt);
};

}  // namespace graphics

#endif