#include<iostream>
#include "Save1.h"
#include "Wizard.h"
#include "Minion.h"
using namespace std;

int main() {
    try {
        // Create instances of Character and Minion
        Character mainCharacter(50);
        Minion minion;

        Save save;

        // Call functions to save character and minion data
        save.saveCharacter(mainCharacter, "Main Character");
        save.saveMinion(minion);
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    }
    return 0;
}