#include "MenuDisplay.h"

namespace graphics {

MenuDisplay::MenuDisplay(GameDataRef data, vector<string> menus, int distance, int displacement)
    : _data(data) {
  // setting default parameter for menu display
  _menu.resize(menus.size());
  // setting up menu 1
  for (int i = 0; i < _menu.size(); i++) {
    _menu[i].setFont(_data->assets.GetFont("menu"));
    _menu[i].setString(menus[i]);
    _menu[i].setCharacterSize(32);
    _menu[i].setFillColor(sf::Color::White);
    _menu[i].setOrigin(_menu[i].getGlobalBounds().width / 2,
                       _menu[i].getGlobalBounds().height / 2);
    _menu[i].setPosition(SCREEN_HEIGHT / 6 + 6 * distance * i + displacement, 4 * SCREEN_WIDTH / 7 + 20);
    if (i > 0){
      if (distance == 0){
            _menu[i].setPosition(SCREEN_HEIGHT / 6 + displacement, 4 * SCREEN_WIDTH / 7 + 70);
      }
    }
    if (SCREEN_HEIGHT / 6 + 6 * distance * i > SCREEN_HEIGHT + 100) {
      _menu[i].setPosition(SCREEN_HEIGHT / 6 - 20, 4 * SCREEN_WIDTH / 7 + 20 + distance);
    }
    //mini menus
    if(i > 3){
      _menu[i].setPosition(SCREEN_HEIGHT / 6 + 6 * distance * (i-4), 4 * SCREEN_WIDTH / 7 + 20);
    }
    if(i > 5){
      _menu[i].setPosition(SCREEN_HEIGHT / 6 + 6 * distance * (i-6), 4 * SCREEN_WIDTH / 7 + 20);
    }
    if(i > 7){
      _menu[i].setPosition(SCREEN_HEIGHT / 6 + 6 * distance * (i-8), 4 * SCREEN_WIDTH / 7 + 20);
    }

    /*if (4 * SCREEN_WIDTH / 7 + 20 + distance > SCREEN_WIDTH + 100) {
      _menu[i].setPosition(SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2);
    }*/
  }
}

void MenuDisplay::Draw(int begin, int end) {
  for (int i = begin - 1; i < end; i++) {
    _data->window.draw(_menu[i]);
  }
}

void MenuDisplay::Update(int begin, int end) {
  for (int i = begin - 1; i < end; i++) {
    _data->window.draw(_menu[i]);
  }
}

}  // namespace graphics