#include "Save1.h"
#include "Wizard.h"
#include "Minion.h"

int main() {
    // Create instances of characters and monsters
    Wizard wizard(150);
    Minion minion("A", 50, 3);

    // Create an instance of Save
    Save saver;

    // Save character and minion details using the saver instance
    saver.saveCharacter(wizard,"Wizard");
    saver.saveMinion(minion);

    return 0;
}
