#ifndef menudisplay_h
#define menudisplay_h
#include <string>
#include <vector> 
/*
#include "Cleric.h"
#include "Fighter.h"
#include "Minion.h"
#include "Wizard.h"
*/

#include <SFML/Graphics.hpp>

#include "GameGraphic.h"

#include "Definitions.h"

namespace graphics {

class MenuDisplay {
 private:
  GameDataRef _data;
  std::vector<sf::Text> _menu;

 public:
    MenuDisplay(GameDataRef data, vector<string> menus, int distance);

    void Draw(int begin, int end);
    void Update(int begin, int end);


};

}  // namespace project
#endif