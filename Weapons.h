#ifndef WEAPONs_H
#define WEAPONs_H

#include <string>
using namespace std;

class Weapons {
protected:
  string name;
  int damage;
  string rarity;
  string perk;

public:
  Weapons(string name, int damage, string rarity, string perk);
  string get_Name(){};
  string get_Rarity(){};
  string get_Perk(){};
};

#endif // WEAPONs_H