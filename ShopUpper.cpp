#include "ShopUpper.h"

namespace graphics {
// shop menu addon
ShopUpper::ShopUpper(GameDataRef data, vector<string> menus, int money)
    : _data(data) {
  // setting default parameter for upper display
  _upper.resize(menus.size());
  // setting up menu 1
  for (int i = 0; i < _upper.size(); i++) {
    _upper[i].setFont(_data->assets.GetFont("menu"));
    if (i == 0) {
      _upper[i].setString(menus[i] + std::to_string(money) + "g");
    } else {
      _upper[i].setString(menus[i]);
    }
    _upper[i].setCharacterSize(32);
    _upper[i].setFillColor(sf::Color::White);
    _upper[i].setOrigin(_upper[i].getGlobalBounds().width / 2,
                        _upper[i].getGlobalBounds().height / 2);
    _upper[i].setPosition(SCREEN_WIDTH / 8 + i*(6*SCREEN_WIDTH/8), SCREEN_HEIGHT / 7);
                         // 6* SCREEN_WIDTH / 7 + i * (5 * SCREEN_WIDTH / 7));
  }
}

void ShopUpper::Draw(int begin, int end) {
      for (int i = begin; i < end; i++) {
    _data->window.draw(_upper[i]);
  }
}

void ShopUpper::Update(vector<string> menus, int money) {
    _upper[0] .setString(menus[1] + std::to_string(money) + "g");

}

}  // namespace graphics
