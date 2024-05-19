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

  c1.serratedSlash(m1);
  m2.specialAttack(c1, c2, c3);
  m1.attack(100, c1);
  c1.attack(300, m2);

  game.round();

  cout << c1.get_health() << endl;
  cout << c2.get_health() << endl;
  cout << c3.get_health() << endl;
  cout << m2.get_health() << endl;
  cout << c3.get_actionPoints() << endl;
  cout << c1.get_isAlive() << endl;
  cout << m2.get_isAlive() << endl;
  cout << c2.get_money() << endl;
}