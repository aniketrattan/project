#include "ActionPoints.h"

namespace graphics {
ActionPoints::ActionPoints(GameDataRef data, int AC) : _data(data) {
  _actionDisplay.setFont(_data->assets.GetFont("menu"));
  _actionDisplay.setString("Action points:");
  _actionDisplay.setCharacterSize(32);
  _actionDisplay.setFillColor(sf::Color::White);
  _actionDisplay.setOrigin(_actionDisplay.getGlobalBounds().width / 2,
                           _actionDisplay.getGlobalBounds().height / 2);
  _actionDisplay.setPosition(SCREEN_HEIGHT / 5, 5 * SCREEN_WIDTH / 7);

  _actionPoints.setFont(_data->assets.GetFont("menu"));
  _actionPoints.setString(to_string(AC));
  _actionPoints.setCharacterSize(32);
  _actionPoints.setFillColor(sf::Color::White);
  _actionPoints.setOrigin(_actionPoints.getGlobalBounds().width / 2,
                          _actionPoints.getGlobalBounds().height / 2);
  _actionPoints.setPosition(SCREEN_HEIGHT / 5 + 120, 5* SCREEN_WIDTH / 7);
}

void ActionPoints::Draw() {
  _data->window.draw(_actionDisplay);
  _data->window.draw(_actionPoints);
}

void ActionPoints::UpdateAction(int actions) {
  _actionPoints.setString(std::to_string(actions));
}
}  // namespace graphics