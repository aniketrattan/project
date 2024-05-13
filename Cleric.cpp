#include "Cleric.h"

Cleric::Cleric(int health) : Character(health) {}

// give an amount of block to all characters i.e if block is 10 points of mitigation then thia gives 3 points to each character 
void Cleric::protection() {
    useActionPoints(1);
}

//removes 1 effect off of character i.e burn or poison effect.
void Cleric::cleanse() {
    useActionPoints(1);
}