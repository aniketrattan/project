#ifndef encounterstate_h
#define encounterstate_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "save.h"
#include "ActionPoints.h"
#include "Boss.h"
#include "Character.h"
#include "Cleric.h"
#include "Definitions.h"
#include "DescriptionDisplay.h"
#include "Fighter.h"
#include "Game.h"
#include "GameGraphic.h"
#include "MenuDisplay.h"
#include "MiniBoss.h"
#include "Minion.h"
#include "NumDisplay.h"
#include "Wizard.h"
#include "state.h"

namespace graphics {

class EncounterState : public State, public save {
 private:
  GameDataRef _data;
  // sprites
  sf::Sprite _background;
  sf::Sprite _fighter;
  sf::Sprite _wizard;
  sf::Sprite _cleric;
  sf::Sprite _encounter;

  // number displays for sprites
  NumDisplay* _fighterNum;
  NumDisplay* _wizardNum;
  NumDisplay* _clericNum;
  NumDisplay* _encounterNum;

  // action display
  ActionPoints* _actionNum;

  // action point tally
  int actionPoints = 2;

  // display for menus
  MenuDisplay* _menuEncounter;
  MenuDisplay* _backspace;
  DescriptionDisplay* _menuDescription;
  MenuDisplay* _actionDisplay;
  // will lock menu when in one
  int menuLock = 0;
  // what values will be shown from the menus vector
  int menuBeginning;
  int menuEnd;
  // draw backspace in the window
  int backOn = 1;
  // menu
  vector<string> menus = {"1) Fighter actions", "2) Wizard actions",
                          "3) Cleric actions",  "0) End round",
                          "4) Serrated Slash",  "5) Anchor Howl",
                          "6) Fireball",        "7) Weaking Ray",
                          "8) Protection",      "9) Cleanse"};
  // backdspace
  vector<string> backspace = {" ", "<-Backspace"};
  // description
  vector<string> descriptions = {
      " ",
      " ",
      " ",
      " ",
      "deals damage to the \nmonster and makes them bleed",
      "all attacks will hit the fighter",
      "charges up a massive attack \nthat lands on the next turn",
      "weakens monster attack",
      "midigates some of \nthe incoming damage",
      "heals all characters \nof any ongoing ailments",
  };
  // number refresh counter
  int triggerNum;
  // need to add a variable in the round function that says what round it is

  // values for each entity
  Minion* m1;
  MiniBoss* mb1;
  Boss* b1;
  Fighter* c1;
  Wizard* c2;
  Cleric* c3;

  Game game;

  //tells what monster we're on
  int monsterCount = get_monstercount();

 public:
  EncounterState(GameDataRef data);

  void Init();

  void handleInput();
  void update(float dt);
  void Draw(float dt);
};

}  // namespace graphics

#endif