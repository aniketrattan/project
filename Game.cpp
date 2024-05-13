#include "Game.h"
#include <iostream>

Game::Game() : fighter(nullptr), wizard(nullptr), cleric(nullptr) {}

void Game::initializeGame() {
    // Create instances of Fighter, Wizard, and Cleric
    fighter = new Fighter(100);
    wizard = new Wizard(100);   
    cleric = new Cleric(100); 
}

void Game::checkEndCondition() {
    if (wizard && wizard->get_isAlive()) {
        return; // Wizard is still alive
    }

    if (cleric && cleric->get_isAlive()) {
        return; // Cleric is still alive
    }

    if (fighter && fighter->get_isAlive()) {
        return; // Fighter is still alive
    }

    std::cout << "Game over" << std::endl;
}
