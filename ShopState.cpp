#include "ShopState.h"
#include "Definitions.h"

namespace graphics {

ShopState::ShopState(GameDataRef data) : _data(data) {}

void ShopState::Init() {
  this->_data->assets.LoadTexture("Shop Background", SHOP_BACKGROUND_FILEPATH);
  this->_data->assets.LoadFont("menu", GAME_FONT);
  _background.setTexture(this->_data->assets.GetTexture("Shop Background"));
  _menuItems = new MenuDisplay(_data, items, 60,0);
  menuBeginning = 1;
  menuEnd = 3;
}

void ShopState::handleInput() {
  sf::Event event;

  while (_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      _data->window.close();
    }
  }
}

void ShopState::update(float dt) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
    // buys the item
    // takes money out of account and asks what charcter you want it on;
    // take item off of display
    menuBeginning = 2;
    menuEnd = 3;
  }
}

void ShopState::Draw(float dt) {
  this->_data->window.clear();

  this->_data->window.draw(_background);

  this->_menuItems->Draw(menuBeginning, menuEnd);

  this->_data->window.display();
}

}  // namespace graphics