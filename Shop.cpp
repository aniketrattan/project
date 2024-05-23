#include "Shop.h"
#include <iostream>

Shop::Shop() {
  // Add some initial items to the shop
  inventory.push_back(Items("Reaper's Blade", 100));
  inventory.push_back(Items("Ring of Fire", 150));
  inventory.push_back(Items("Holy Water", 100));
  inventory.push_back(Items("Life Essence", 100));
  inventory.push_back(Items("Action Boost", 100));
  inventory.push_back(Items("Second Chance", 100));
}

// add some items to the shop
void Shop::addItem(const Items &item) { inventory.push_back(item); }

// display the items in the shop
void Shop::displayItems() const {
  cout << "Shop Inventory:" << endl;
  for (const auto &item : inventory) {
    cout << "Name: " << item.get_name() << ", Cost: " << item.get_cost()
         << endl;
  }
}

// add item to charcater inventory
bool Shop::buyItem(Character &character, const string &itemName) {
  for (const auto &item : inventory) {
    if (item.get_name() == itemName) {
      if (character.get_money() >= item.get_cost()) {
        character.addItem(item);
        character.set_money(character.get_money() - item.get_cost());
        cout << itemName << " purchased successfully!" << endl;
        return true;
      } else {
        cout << "Not enough money to buy " << itemName << endl;
        return false;
      }
    }
  }
  cout << itemName << " not found in shop inventory." << endl;
  return false;
}
