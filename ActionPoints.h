#ifndef actionpoints_h
#define actionpoints_h

#include <SFML/Graphics.hpp>

#include "Definitions.h"
#include "GameGraphic.h"

namespace graphics {

class ActionPoints {
 private:
  GameDataRef _data;
  sf::Text _actionDisplay;
  sf::Text _actionPoints;

 public:
  ActionPoints(GameDataRef data, int AC);

  void Draw();
  void UpdateAction(int actions);

  ~ActionPoints();
};

}  // namespace graphics

#endif