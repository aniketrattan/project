#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Character.h"
#include "Items.h"
using namespace std;

class Shop {
private:
    vector<Items> inventory;

public:
    Shop();
    void addItem(const Items& item);
    void displayItems() const;
    bool buyItem(Character& character, const string& itemName);
};

#endif // SHOP_H
