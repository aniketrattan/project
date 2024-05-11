#include "Character.cpp"
#include "Minion.cpp"
#include "Fighter.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Character c1(100);
  Fighter f1(100);
  Minion m1("Minion", 100, 1);
  f1.attack(20, m1);
  cout << m1.get_health() << endl;
}