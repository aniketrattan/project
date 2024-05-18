#include "MapState.h"
#include "EncounterState.h"
#include "CampsiteState.h"
#include "ShopState.h"

namespace graphics {

MapState::MapState(GameDataRef data) : _data(data) {}

void MapState::Init() {
  this->_data->assets.LoadTexture("Map Background", MAP_BACKGROUND_FILEPATH);
  this->_data->assets.LoadFont("menu", GAME_FONT);
  _background.setTexture(this->_data->assets.GetTexture("Map Background"));
  _menuPaths = new MenuDisplay(_data, paths, 60, 0);
  menuBeginning = 1;
  menuEnd = 3;
}
void MapState::handleInput() {
  sf::Event event;

  while (_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      _data->window.close();
    }
  }
}
void MapState::update(float dt) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    _data->machine.AddState(StateRef(new EncounterState(this->_data)), true);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    _data->machine.AddState(StateRef(new CampsiteState(this->_data)), true);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    _data->machine.AddState(StateRef(new ShopState(this->_data)), true);
  }
}
void MapState::Draw(float dt) {
  this->_data->window.clear();

  this->_data->window.draw(_background);

  this->_menuPaths->Draw(menuBeginning, menuEnd);

  this->_data->window.display();
}
}  // namespace graphics