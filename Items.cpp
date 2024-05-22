#include "Items.h"

// constructor
Items::Items(string name, int cost) : name(name), cost(cost) {}

// getters
string Items::get_name() const { return name; }
int Items::get_cost() const { return cost; }
