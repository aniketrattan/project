#ifndef SHOP_H
#define SHOP_H

#include "Character.h"
#include "Items.h"
#include <vector>

using namespace std;

class Shop {
private:
  // vector for storing items
  vector<Items> inventory;

public:
  // default constructor
  Shop();

  // add item to inventory
  void addItem(const Items &item);

  // display inventory
  void displayItems() const;

  // add item to character inventory
  bool buyItem(Character &character, const string &itemName);
};

#endif // SHOP_H
