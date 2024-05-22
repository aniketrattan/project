#ifndef campsitestate_h
#define campsitestate_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "GameGraphic.h"
#include "MenuDisplay.h"
#include "state.h"
#include "EncounterState.h"

namespace graphics {

class CampsiteState : public State {
 private:
  GameDataRef _data;
  // sprites
  sf::Sprite _background;

  MenuDisplay* _menuRest;

  // what values will be shown from the paths vector
  int menuBeginning;
  int menuEnd;

  vector<string> paths = {"All members of the party have been healed.", "To save progress press Enter.", "Progress Saved.", "up) To Encounter"};

 public:
  CampsiteState(GameDataRef data);

  void Init();

  void handleInput();
  void update(float dt);
  void Draw(float dt);
};

}  // namespace graphics

#endif