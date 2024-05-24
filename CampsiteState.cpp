#include "CampsiteState.h"

#include "Definitions.h"

#include "Save1.h"

namespace graphics {

CampsiteState::CampsiteState(GameDataRef data) : _data(data) {}

void CampsiteState::Init() {
  this->_data->assets.LoadTexture("Campsite Background",
                                  CAMPSITE_BACKGROUND_FILEPATH);
  this->_data->assets.LoadFont("menu", GAME_FONT);
  _background.setTexture(this->_data->assets.GetTexture("Campsite Background"));
  _menuRest = new MenuDisplay(_data, paths, 0, 400);
  menuBeginning = 1;
  menuEnd = 2;
}

void CampsiteState::handleInput() {
  sf::Event event;

  while (_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      std::ofstream writeFile(SAVE_MONSTER_FILE);

      if (writeFile.is_open()) {
        writeFile << 1;
      }

      writeFile.close();
      _data->window.close();
      _data->window.close();
    }
    if (event.type == (sf::Event::KeyPressed)) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        // call save state function
        menuBeginning = 3;
        menuEnd = 4;
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
        // transports to encounter
        _data->machine.AddState(StateRef(new MapState(this->_data)),
                                true);
      }
    }
  }
}

void CampsiteState::update(float dt) {}
void CampsiteState::Draw(float dt) {
  this->_data->window.clear();

  this->_data->window.draw(_background);

  this->_menuRest->Draw(menuBeginning, menuEnd);

  this->_data->window.display();
}
}  // namespace graphics