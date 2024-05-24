#include "Boss.cpp"
#include "Character.cpp"
#include "Cleric.cpp"
#include "Fighter.cpp"
#include "Game.cpp"
#include "Items.cpp"
#include "MiniBoss.cpp"
#include "Minion.cpp"
#include "Save1.h"
#include "Shop.cpp"
#include "Wizard.cpp"
#include <iostream>
#include <string>

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

  game.setMinion(&m1);
  game.setMiniBoss(&mb1);
  game.setBoss(&b1);
  game.setFighter(&c1);
  game.setWizard(&c2);
  game.setCleric(&c3);
  c1.set_money(200);
  c1.resetAnchoring();
  c2.resetAnchoring();
  c3.resetAnchoring();

  c3.protection();
  shop.buyItem(c3, "Holy Water");
  cout << c3.get_isProtecting() << endl;

  game.round();

  cout << c1.getProtectionAmount() << endl;
  cout << c3.getProtectionAmount() << endl;
  mb1.specialAttack(c1, c2, c3);

  cout << c1.get_health() << endl;
  cout << c2.get_health() << endl;
  cout << c3.get_health() << endl;
  cout << c1.get_actionPoints() << endl;
}