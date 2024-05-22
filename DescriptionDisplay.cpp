#include "DescriptionDisplay.h"
#include "MenuDisplay.h"

namespace graphics {

DescriptionDisplay::DescriptionDisplay(GameDataRef data, vector<string> descriptions, vector<sf::Text> menu, int x, int y)
 : _data(data) {
  // setting default parameter for menu display
  description.resize(descriptions.size());
  // setting up menu 1
  for (int i = 0; i < description.size(); i++) {
    description[i].setFont(_data->assets.GetFont("menu"));
    description[i].setString(descriptions[i]);
    description[i].setCharacterSize(24);
    description[i].setFillColor(sf::Color::White);
    description[i].setOrigin(description[i].getGlobalBounds().width / 2,
                       description[i].getGlobalBounds().height / 2);
    description[i].setPosition(Get_positionX(menu, (i)) + x, Get_positionY(menu, (i)) + y);
    //printf("%d x position is, %0.2f and y position is, %0.2f", i, Get_positionX(menu, (i*2)),Get_positionY(menu, (i*2+1)));
  }
}

void DescriptionDisplay::Draw(int begin, int end) {
  for (int i = begin - 1; i < end; i++) {
    _data->window.draw(description[i]);
  }
}

void DescriptionDisplay::Draw(int begin, int end, vector<int> bought) {
  for (int i = begin - 1; i < end; i++) {
        if (count(bought.begin(), bought.end(), i) == 0) {
    _data->window.draw(description[i]);
        }
  }
}

void DescriptionDisplay::Update(int begin, int end) {
  for (int i = begin - 1; i < end; i++) {
    _data->window.draw(description[i]);
  }
}

float DescriptionDisplay::Get_positionX(vector<sf::Text> menu, int index) {return(menu[index].getPosition().x);}

float DescriptionDisplay::Get_positionY(vector<sf::Text> menu, int index) {return (menu[index].getPosition().y);}

}  // namespace graphics