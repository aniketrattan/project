#ifndef descrptiondisplay_h
#define descrptiondisplay_h
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Definitions.h"
#include "GameGraphic.h"

#include "MenuDisplay.h"

namespace graphics {

class DescriptionDisplay {
 private:
  GameDataRef _data;
  std::vector<sf::Text> description;
  

 public:
  DescriptionDisplay(GameDataRef data, vector<string> descriptions, vector<sf::Text> menu, int distance, int displacement);

  void Draw(int begin, int end);
  void Draw(int begin, int end, vector<int> bought);
  void Update(int begin, int end);

  ~DescriptionDisplay();

  float Get_positionX(vector<sf::Text> menu, int index);
  float Get_positionY(vector<sf::Text> menu, int index);
};

}  // namespace graphics

#endif