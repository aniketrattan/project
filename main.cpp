#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Boss.cpp"
#include "Character.cpp"
#include "Cleric.cpp"
#include "Definitions.h"
#include "Fighter.cpp"
#include "Game.cpp"
#include "Game.h"
#include "GameGraphic.h"
#include "Items.cpp"
#include "MiniBoss.cpp"
#include "Minion.cpp"
#include "Shop.cpp"
#include "Wizard.cpp"

using namespace std;

int main() {
  Minion m1("Minion", 100, 1);
  Minion m2("Minion2", 150, 1);
  MiniBoss mb1("MiniBoss", 250, 2);
  Boss b1("Boss", 500, 3);
  Fighter c1(100);
  Wizard c2(100);
  Cleric c3(100);

  Game game;
  Shop shop;



  graphics::GameGraphic(SCREEN_WIDTH, SCREEN_HEIGHT, "Castle Quest");

  return 0;
}