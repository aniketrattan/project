#include "ShopState.h"

#include "Definitions.h"

namespace graphics {

ShopState::ShopState(GameDataRef data) : _data(data) {}

void ShopState::Init() {
  this->_data->assets.LoadTexture("Shop Background", SHOP_BACKGROUND_FILEPATH);
  this->_data->assets.LoadFont("menu", GAME_FONT);
  _background.setTexture(this->_data->assets.GetTexture("Shop Background"));
  _menuItems = new MenuDisplay(_data, items);
  _menuUpper = new ShopUpper(_data, upper, money);
  _ItemDescription = new DescriptionDisplay(_data, descriptions, _menuItems->Get_Text(), 20, 50);
  _ItemDescriptionLast = new DescriptionDisplay(_data, descriptions, _menuItems->Get_Text(), 40, 90);
  _bought.resize(6);
  // to ensure that it doesn't start with any values of items
  for (int j = 7; j < 13; j++) {
    _bought[_boughtItems] = j;
    _boughtItems += 1;
  }
  // reset bought items for the rest of the file
  _boughtItems = 0;

  // tells what index's of the menu vector should be drawn
  menuBeginning = 1;
  menuEnd = 6;
}

void ShopState::handleInput() {
  sf::Event event;

  while (_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      _data->window.close();
    }
    if (event.type == (sf::Event::KeyPressed)) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        // buys the item
        // takes money out of account and asks what charcter you want it on;
        // take item off of display
        _bought[_boughtItems] = 0;
        _boughtItems += 1;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        // buys the item
        // takes money out of account and asks what charcter you want it on;
        // take item off of display
        _bought[_boughtItems] = 1;
        _boughtItems += 1;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        // buys the item
        // takes money out of account and asks what charcter you want it on;
        // take item off of display
        _bought[_boughtItems] = 2;
        _boughtItems += 1;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        // buys the item
        // takes money out of account and asks what charcter you want it on;
        // take item off of display
        _bought[_boughtItems] = 3;
        _boughtItems += 1;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
        // buys the item
        // takes money out of account and asks what charcter you want it on;
        // take item off of display
        _bought[_boughtItems] = 4;
        _boughtItems += 1;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
        // buys the item
        // takes money out of account and asks what charcter you want it on;
        // take item off of display
        _bought[_boughtItems] = 5;
        _boughtItems += 1;
      }

       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          //transports to encounter
          _data->machine.AddState(StateRef(new EncounterState(this->_data)), true);
      }
    }
  }
}

void ShopState::update(float dt) {}

void ShopState::Draw(float dt) {
  _data->window.clear();

  _data->window.draw(_background);

  _menuItems->Draw(menuBeginning, menuEnd, _bought);
  _menuUpper->Draw(0,2);
  _ItemDescription->Draw(menuBeginning, menuEnd - 1, _bought);
  _ItemDescriptionLast->Draw(6, 6, _bought);

  _data->window.display();
}

}  // namespace graphics