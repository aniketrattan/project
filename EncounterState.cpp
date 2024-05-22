#include "EncounterState.h"

#include "Boss.h"
#include "Character.h"
#include "Cleric.h"
#include "Fighter.h"
#include "Game.h"
#include "MapState.h"
#include "MiniBoss.h"
#include "Minion.h"
#include "Wizard.h"

namespace graphics {

EncounterState::EncounterState(GameDataRef data) : _data(data) {}

// initialize function
void EncounterState::Init() {

  m1 = new Minion("Minion", 100, 1);
  mb1 = new MiniBoss("MiniBoss", 250, 2);
  b1 = new Boss("Boss", 500, 3);
  c1 = new Fighter(100);
  c2 = new Wizard(100);
  c3 = new Cleric(100);

  game.setMinion(m1);
  game.setMiniBoss(mb1);
  game.setBoss(b1);
  game.setFighter(c1);
  game.setWizard(c2);
  game.setCleric(c3);

  // load background
  _data->assets.LoadTexture("Encounter Background",
                            ENCOUNTER_BACKGROUND_FILEPATH);
  // load character sprites
  _data->assets.LoadTexture("Fighter", FIGHTER_SPRITE_FILEPATH);
  _data->assets.LoadTexture("Wizard", WIZARD_SPRITE_FILEPATH);
  _data->assets.LoadTexture("Cleric", CLERIC_SPRITE_FILEPATH);

  // load monster sprite
  if (monsterCount == 3) {
    _data->assets.LoadTexture("Encounter", BOSS_SPRITE_FILEPATH);
  } else if (monsterCount == 2) {
    _data->assets.LoadTexture("Encounter", MINIBOSS_SPRITE_FILEPATH);
  } else {
    _data->assets.LoadTexture("Encounter", MINION_SPRITE_FILEPATH);
  }

  // load menu text
  _data->assets.LoadFont("menu", GAME_FONT);

  // health and damage
  _data->assets.LoadFont("health", GAME_FONT);

  _data->assets.LoadFont("damage", GAME_FONT);

  // set png to there respective data member
  _background.setTexture(
      this->_data->assets.GetTexture("Encounter Background"));
  _fighter.setTexture(this->_data->assets.GetTexture("Fighter"));
  _wizard.setTexture(this->_data->assets.GetTexture("Wizard"));
  _cleric.setTexture(this->_data->assets.GetTexture("Cleric"));
  _encounter.setTexture(this->_data->assets.GetTexture("Encounter"));

  // setting position of each sprite
  _fighter.setPosition((571 - 100) - (_fighter.getGlobalBounds().width / 2),
                       _fighter.getGlobalBounds().height / 2 + 140);
  _wizard.setPosition((571 / 2) - (_wizard.getGlobalBounds().width / 2),
                      _wizard.getGlobalBounds().height / 2 + 140);
  _cleric.setPosition((571 / 4) - (_cleric.getGlobalBounds().width / 2),
                      _cleric.getGlobalBounds().height / 2 + 140);

  if (monsterCount == 3) {
    _encounter.setPosition((4 * SCREEN_WIDTH / 7),
                           _encounter.getGlobalBounds().height / 2 - 110);
  } else if (monsterCount == 2) {
    _encounter.setPosition((5 * 571 / 4),
                           _encounter.getGlobalBounds().height / 2);
  } else {
    _encounter.setPosition((5 * 571 / 4),
                           _encounter.getGlobalBounds().height / 2 + 130);
  }

  // setting up NumDisplay for each sprite
  _fighterNum = new NumDisplay(_data, _fighter);
  _wizardNum = new NumDisplay(_data, _wizard);
  _clericNum = new NumDisplay(_data, _cleric);
  _encounterNum = new NumDisplay(_data, _encounter);

  // menu
  _menuEncounter = new MenuDisplay(_data, menus, 60, 0);
  _backspace = new MenuDisplay(_data, backspace, 120, 0);
  _menuDescription = new DescriptionDisplay(_data, descriptions,
                                            _menuEncounter->Get_Text(), 50, 50);

  // what values will be shown from the menus vector
  menuBeginning = 1;
  menuEnd = 4;
  // action point
  _actionNum = new ActionPoints(_data);

  // round() calls round function
  _fighterNum->UpdateHealth(c1->get_health());
  _wizardNum->UpdateHealth(c2->get_health());
  _clericNum->UpdateHealth(c3->get_health());

  if (monsterCount == 3) {
    _encounterNum->UpdateHealth(b1->get_health());
  } else if (monsterCount == 2) {
    _encounterNum->UpdateHealth(mb1->get_health());
  } else {
    _encounterNum->UpdateHealth(m1->get_health());
  }
}

void EncounterState::handleInput() {
  sf::Event event;

  while (_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      _data->window.close();
    }
    if (event.type == (sf::Event::KeyPressed)) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
        game.round();
        // monster attack
        if (monsterCount == 3) {
          b1->specialAttack(c1[0], c2[0], c3[0]);
        } else if (monsterCount == 2) {
          mb1->specialAttack(c1[0], c2[0], c3[0]);
        } else {
          m1->specialAttack(c1[0], c2[0], c3[0]);
        }
        actionPoints = 2;
        _actionNum->UpdateAction(actionPoints);
        // updates health
        _fighterNum->UpdateHealth(c1->get_health());
        _wizardNum->UpdateHealth(c2->get_health());
        _clericNum->UpdateHealth(c3->get_health());
        if (monsterCount == 3) {
          _encounterNum->UpdateHealth(b1->get_health());
        } else if (monsterCount == 2) {
          _encounterNum->UpdateHealth(mb1->get_health());
        } else {
          _encounterNum->UpdateHealth(m1->get_health());
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        if (actionPoints > 0) {
          if (menuLock == 0) {
            // locks menu to fighter
            menuLock = 1;
            // tells which string values are to be drawn
            menuBeginning = 5;
            menuEnd = 6;
            // draws backspace
            backOn = 2;
          }
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        if (actionPoints > 0) {
          if (menuLock == 0) {
            // locks menu to wizard
            menuLock = 2;
            // tells which string values are to be drawn
            menuBeginning = 7;
            menuEnd = 8;
            // draws backspace
            backOn = 2;
          }
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        if (actionPoints > 0) {
          if (menuLock == 0) {
            // locks menu to cleric
            menuLock = 3;
            // tells which string values are to be drawn
            menuBeginning = 9;
            menuEnd = 10;
            // draws backspace
            backOn = 2;
          }
        }
      }

      // fighter menu
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        if (menuLock == 1) {
          if (monsterCount == 3) {
            c1->serratedSlash(b1[0]);
          } else if (monsterCount == 2) {
            c1->serratedSlash(mb1[0]);
          } else {
            c1->serratedSlash(m1[0]);
          }
          actionPoints -= 1;
          _actionNum->UpdateAction(actionPoints);
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          if (monsterCount == 3) {
            _encounterNum->UpdateHealth(b1->get_health(), 1);
          } else if (monsterCount == 2) {
            _encounterNum->UpdateHealth(mb1->get_health(), 1);
          } else {
            _encounterNum->UpdateHealth(m1->get_health(), 1);
          }
          backOn = 0;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
        if (menuLock == 1) {
          c1->anchorHowl();
          actionPoints -= 1;
          _actionNum->UpdateAction(actionPoints);
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          backOn = 0;
        }
      }

      // wizard menu
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
        if (menuLock == 2) {
          if (monsterCount == 3) {
            c2->fireball(b1[0]);
          } else if (monsterCount == 2) {
            c2->fireball(mb1[0]);
          } else {
            c2->fireball(m1[0]);
          }
          actionPoints -= 1;
          _actionNum->UpdateAction(actionPoints);
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          if (monsterCount == 3) {
            _encounterNum->UpdateHealth(b1->get_health(), 0);
          } else if (monsterCount == 2) {
            _encounterNum->UpdateHealth(mb1->get_health(), 0);
          } else {
            _encounterNum->UpdateHealth(m1->get_health(), 0);
          }
          backOn = 0;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
        if (menuLock == 2) {
          c2->weakeningRay();
          actionPoints -= 1;
          _actionNum->UpdateAction(actionPoints);
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          backOn = 0;
        }
      }

      // cleric menu
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
        if (menuLock == 3) {
          c3->protection();
          actionPoints -= 1;
          _actionNum->UpdateAction(actionPoints);
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          backOn = 0;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
        if (menuLock == 3) {
          c3->cleanse(c1[0], c2[0]);
          actionPoints -= 1;
          _actionNum->UpdateAction(actionPoints);
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          backOn = 0;
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        if (menuLock > 0) {
          menuBeginning = 1;
          menuEnd = 4;
          menuLock = 0;
          backOn = 0;
        }
      }
    }
  }
}

void EncounterState::update(float dt) {
  // general menu
  // create function to do this more descretly

  // end round
  /*
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
    if (menuLock == 0) {
    }
  }*/
  // updates the encounter damage

  m1->checkHealth();
  mb1->checkHealth();
  b1->checkHealth();

  // runs if minion is dead
  if (monsterCount == 3) {
    if (!b1->get_isAlive()) {
      // win message
      // display amount of gold made
      // transports to map
      game.round();
      set_monstercount(game.getMonsterCount());
      std::cout << game.getMonsterCount() << endl;
      _data->machine.AddState(StateRef(new MapState(this->_data)));
    }
  } else if (monsterCount == 2) {
    if (!mb1->get_isAlive()) {
      // win message
      // display amount of gold made
      // transports to map
      game.round();
      set_monstercount(game.getMonsterCount());
      std::cout << game.getMonsterCount() << endl;
      _data->machine.AddState(StateRef(new MapState(this->_data)));
    }
  } else {
    if (!m1->get_isAlive()) {
      // win message
      // display amount of gold made
      // transports to map
      game.round();
      set_monstercount(game.getMonsterCount());
      std::cout << game.getMonsterCount() << endl;
      _data->machine.AddState(StateRef(new MapState(this->_data)));
    }
  }
}

void EncounterState::Draw(float dt) {
  // clears the window
  _data->window.clear();
  // adds all the sprites to the window
  _data->window.draw(_background);
  _data->window.draw(_fighter);
  _data->window.draw(_wizard);
  _data->window.draw(_cleric);
  _data->window.draw(_encounter);

  // draws the sprites
  _fighterNum->Draw();
  _wizardNum->Draw();
  _clericNum->Draw();
  _encounterNum->Draw();
  _menuEncounter->Draw(menuBeginning, menuEnd);
  _menuDescription->Draw(menuBeginning, menuEnd);
  _backspace->Draw(1, backOn);

  // draw action points
  _actionNum->Draw();

  // dispalys the sprites
  _data->window.display();
}
}  // namespace graphics