#include "Character.h"
#include "Minion.h"
#include "Fighter.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Character c1(100);
  Minion m1("Minion", 100, 1);
  Fighter f1(100);
  f1.serratedSlash(m1);
  f1.serratedSlash(m1);
  c1.attack(100, m1);
  cout << m1.get_health() << endl;
  cout << m1.get_bleed() << endl;
  cout << m1.get_isAlive() << endl;
  cout << f1.get_actionPoints() << endl;
}