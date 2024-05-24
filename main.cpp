#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Boss.h"
#include "Character.h"
#include "Cleric.h"
#include "Definitions.h"
#include "Fighter.h"
#include "Game.h"
#include "GameGraphic.h"
#include "Items.h"
#include "MiniBoss.h"
#include "Minion.h"
#include "Shop.h"
#include "Wizard.h"
#include <fstream>

using namespace std;

int main() {

  graphics::GameGraphic(SCREEN_WIDTH, SCREEN_HEIGHT, "Castle Quest");

  return 0;
}