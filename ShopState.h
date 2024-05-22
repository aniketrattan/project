#ifndef shopstate_h
#define shopstate_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>

#include "Definitions.h"
#include "GameGraphic.h"
#include "MenuDisplay.h"
#include "DescriptionDisplay.h"
#include "state.h"
#include "ShopUpper.h"
#include "EncounterState.h"

namespace graphics {

class ShopState : public State {
 private:
  GameDataRef _data;
  // sprites
  sf::Sprite _background;
  vector<int> _bought;
  int _boughtItems = 0;
  //menu items
  MenuDisplay* _menuItems;
  ShopUpper* _menuUpper;
  DescriptionDisplay* _ItemDescription;
  DescriptionDisplay* _ItemDescriptionLast;

  //need to work
  Fighter* c1;

  //money
  int money = c1->get_money();
  // what values will be shown from the paths vector
  int menuBeginning;
  int menuEnd;

  vector<string> items = {"1.Reapers blade 200g", "2.Fire Ring 200g", "3.Holy Water 200g", 
  "4.Life essence 400g", "5.Action boost 500g", "6.Second chance 500g"};

  vector<string> descriptions = {"adds more damage and \nbleed to Severing Slash","increases damage for fireball","increases damage \nmitagation from protection",
  "increase max health \nof all characters", "adds 1 more action point \nper round", 
  "when a character would drop \nto 0 health they instead go\nto half of their max. This item \ncan only be used once."};

  vector<string> upper = {"Gold: ", "up) encounter"};

 public:
  ShopState(GameDataRef data);

  void Init();

  void handleInput();
  void update(float dt);
  void Draw(float dt);
};

}  // namespace graphics

#endif