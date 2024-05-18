#include "NumDisplay.h"
#include "Definitions.h"

#include <string>

namespace graphics {

NumDisplay::NumDisplay(GameDataRef data, sf::Sprite character) : _data(data) {
  // setting default parameter for health display
  _health.setFont(_data->assets.GetFont("health"));
  _health.setString("10");
  _health.setCharacterSize(64);
  _health.setFillColor(sf::Color::Red);
  _health.setOrigin(_health.getGlobalBounds().width / 2, _health.getGlobalBounds().height / 2);
  _health.setPosition(
      character.getPosition().x + character.getGlobalBounds().height/2,
      character.getPosition().y + character.getGlobalBounds().width);

  // setting default parameter for damage display
  _damage.setFont(_data->assets.GetFont("damage"));
  _damage.setString("6");
  _damage.setCharacterSize(64);
  _damage.setFillColor(sf::Color::White);
  _damage.setOrigin(_damage.getGlobalBounds().width / 2, _damage.getGlobalBounds().height / 2);
  _damage.setPosition(
      character.getPosition().x + character.getGlobalBounds().height / 2,
      character.getPosition().y-50);
}

void NumDisplay::Draw() {
  _data->window.draw(_health);
  _data->window.draw(_damage);
}
void NumDisplay::UpdateHealth(int health, sf::Sprite character) {
  _health.setString(std::to_string(health));
}
void NumDisplay::UpdateDamage(int damage, sf::Sprite character) {
  _damage.setString(std::to_string(damage));
}
}  // namespace project