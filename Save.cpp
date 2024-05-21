#include <iostream>
#include "Save.h"

void Save::saveCharacter(Character& character,std::string& filename) {
    std::ofstream file(filename, std::ios::app); 

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    // Character's Details:
    file << "Character's Health: " << character.get_health() << std::endl;
    file << "Is the character alive: " << (character.get_isAlive() ? "Yes" : "No") << std::endl;

    file.close();
    std::cout << "Character saved successfully to " << filename << std::endl;
}
void Save::saveMinion(Minion& minion,std::string& filename) {
    std::ofstream file(filename, std::ios::app); 

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    //Minions Details:
    file << "Minion Name: " << minion.get_name() << std::endl;
    file << "Minion's Health: " << minion.get_health() << std::endl;
    file << "Minion Level: " << minion.get_level() << std::endl;
    file << "Is the minion alive: " << (minion.get_isAlive() ? "Yes" : "No") << std::endl;

    file.close();
    std::cout << "Minion saved successfully to " << filename << std::endl;
}

void Save::saveMiniBoss(MiniBoss& miniBoss,std::string& filename) {
    std::ofstream file(filename, std::ios::app); 

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    //MiniBoss Details:
    file << "Mini-Boss Name: " << miniBoss.get_name() << std::endl;
    file << "Mini-Boss's Health: " << miniBoss.get_health() << std::endl;
     file << "Mini-Boss Level: " << miniBoss.get_level() << std::endl;
    file << "Is the Mini-Boss alive: " << (miniBoss.get_isAlive() ? "Yes" : "No") << std::endl;

    file.close();
    std::cout << "MiniBoss saved successfully to " << filename << std::endl;
}

void Save::saveBoss(Boss& boss,std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Open file in append mode

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    //Boss Details:
    file << "Boss Name: " << boss.get_name() << std::endl;
    file << "Boss's Health: " << boss.get_health() << std::endl;
    file << "Boss's Level: " << boss.get_level() << std::endl;
    file << "Is the Boss alive: " << (boss.get_isAlive() ? "Yes" : "No") << std::endl;
    file.close();
    std::cout << "Boss saved successfully to " << filename << std::endl;
}
