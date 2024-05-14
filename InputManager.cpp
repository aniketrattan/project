#include "InputManager.h"

namespace project {
bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) {
  if(sf::Mouse::isButtonPressed(button)){
    sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
    if(tempRect.contains(sf::Mouse::getPosition(window))){
        return true;
    }
  }
}

sf::Vector2i InputManager::GetMOusePosition(sf::RenderWindow& window) {
  return sf::Mouse::getPosition(window);
}
}  // namespace project