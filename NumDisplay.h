#ifndef numdisplay_h
#define numdisplay_h
#include <string>

#include "Cleric.h"
#include "Fighter.h"
#include "Minion.h"
#include "Wizard.h"


#include <SFML/Graphics.hpp>

#include "GameGraphic.h"

namespace graphics {

class NumDisplay {
 private:
  GameDataRef _data;
  sf::Text _health;
  sf::Text _damage;

 public:
  NumDisplay(GameDataRef data, sf::Sprite character);

  void Draw();
  void UpdateHealth(int health);
  void UpdateDamage(int damage, string type);

  ~NumDisplay();
};

}  // namespace graphics
#endif