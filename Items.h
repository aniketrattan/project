#ifndef ITEMS_H
#define ITEMS_H

#include <string>
using namespace std;

class Items {
private:
    string name;
    int cost;

public:
    Items(string name, int cost);
    string get_name() const;
    int get_cost() const;
};

#endif // ITEMS_H
