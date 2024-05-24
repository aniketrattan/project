#ifndef ITEMS_H
#define ITEMS_H

#include <string>
using namespace std;

class Items {
private:
  string name;
  int cost;

public:
  // constructor for creating items
  Items(string name, int cost);

  // getters
  string get_name() const;
  int get_cost() const;
};

#endif // ITEMS_H
