#ifndef shopupper_h
#define shopupper_h
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

class ShopUpper {
 private:
  GameDataRef _data;
  vector<sf::Text> _upper;

 public:
  //shop upper menu
  ShopUpper(GameDataRef data, vector<string> menus, int money);

  void Draw(int begin, int end);
  void Update(vector<string> menus, int money);

  ~ShopUpper();
};

}  // namespace graphics
#endif