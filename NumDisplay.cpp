#include "NumDisplay.h"

#include <string>

#include "Definitions.h"

namespace graphics {

NumDisplay::NumDisplay(GameDataRef data, sf::Sprite character) : _data(data) {
  // setting default parameter for health display
  _health.setFont(_data->assets.GetFont("health"));
  _health.setString(" ");
  _health.setCharacterSize(32);
  //32
  _health.setFillColor(sf::Color::Red);
  _health.setOrigin(_health.getGlobalBounds().width / 2,
                    _health.getGlobalBounds().height / 2);
  _health.setPosition(
      character.getPosition().x + character.getGlobalBounds().height / 2 - 20,
      character.getPosition().y + character.getGlobalBounds().width);

  // setting default parameter for damage display
  _damage.setFont(_data->assets.GetFont("damage"));
  _damage.setString(" ");
  _damage.setCharacterSize(64);
  _damage.setFillColor(sf::Color::White);
  _damage.setOrigin(_damage.getGlobalBounds().width / 2,
                    _damage.getGlobalBounds().height / 2);
  _damage.setPosition(
      character.getPosition().x + character.getGlobalBounds().height / 2,
      character.getPosition().y - 50);
}

void NumDisplay::Draw() {
  _data->window.draw(_health);
  _data->window.draw(_damage);
}
void NumDisplay::UpdateHealth(int health) {
  _health.setString(std::to_string(health));
}

void NumDisplay::UpdateHealth(int health, int bleed) {
  _bleed = bleed;
  string bleedDis = std::to_string(_bleed);
  _health.setString(std::to_string(health) + " - " + bleedDis + " bleed");
  _health.setOrigin(_health.getGlobalBounds().width / 2 - 10,
                    _health.getGlobalBounds().height / 2 - 10);
}

void NumDisplay::UpdateDamage(int damage, string type) {
  if (type == "Fire") {
    _damage.setCharacterSize(32);
    _damage.setString(std::to_string(damage) + " + Fire");
    _damage.setFillColor(sf::Color::Yellow);
    _damage.setOrigin(_damage.getGlobalBounds().width / 2,
                      _damage.getGlobalBounds().height / 2);
  } else if (type == "Poison") {
    _damage.setCharacterSize(32);
    _damage.setString(std::to_string(damage) + " + Poison");
    _damage.setFillColor(sf::Color::Green);
    _damage.setOrigin(_damage.getGlobalBounds().width / 2,
                      _damage.getGlobalBounds().height / 2);
  } else {
    _damage.setCharacterSize(32);
    _damage.setString(std::to_string(damage));
    _damage.setFillColor(sf::Color::White);
    _damage.setOrigin(_damage.getGlobalBounds().width / 2,
                      _damage.getGlobalBounds().height / 2);
  }
}

}  // namespace graphics