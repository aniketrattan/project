#include "Weapons.h"

Weapons::Weapons(string name, int damage, string rarity, string perk) {
  this->name = name;
  this->damage = damage;
  this->rarity = rarity;
  this->perk = perk;
}

string Weapons::get_Name() { return name; }

string Weapons::get_Rarity() { return rarity; }

string Weapons::get_Perk() { return perk; }