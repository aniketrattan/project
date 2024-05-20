#include "Boss.cpp"
#include "Character.cpp"
#include "Cleric.cpp"
#include "Fighter.cpp"
#include "Game.cpp"
#include "MiniBoss.cpp"
#include "Minion.cpp"
#include "Wizard.cpp"
#include <iostream>
#include <string>


using namespace std;

int main() {
  Minion m1("Minion", 100, 1);
  MiniBoss m2("MiniBoss", 250, 2);
  Boss m3("Boss", 500, 3);
  Fighter c1(100);
  Wizard c2(100);
  Cleric c3(100);

  Game game;

  game.setMinion(&m1);
  game.setMiniBoss(&m2);
  game.setBoss(&m3);
  game.setFighter(&c1);
  game.setWizard(&c2);
  game.setCleric(&c3);

  c2.weakeningRay();
  m1.attack(50, c2);

  game.round();
  cout << c2.get_isWeakening() << endl;

  m1.attack(50, c2);

  cout << c1.get_health() << endl;
  cout << c2.get_health() << endl;
  cout << c3.get_health() << endl;
}