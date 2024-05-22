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

#include "Definitions.h"
#include "GameGraphic.h"

namespace graphics {

class MenuDisplay {
 private:
  GameDataRef _data;
  vector<sf::Text> _menu;

 public:
  //encouter menu
  MenuDisplay(GameDataRef data, vector<string> menus, int distance,
              int displacement);
  //shop menu
  MenuDisplay(GameDataRef data, vector<string> menus);
  //upper menu
  MenuDisplay(GameDataRef data,int money, vector<string> menus);

  void Draw(int begin, int end);
  void Draw(int begin, int end, vector<int> bought);
  void Update(int begin, int end);
  vector<sf::Text> Get_Text();

  ~MenuDisplay();
};

}  // namespace graphics
#endif