#include "Save.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

string Save::generateFilename(const string& prefix) {
    // Generating filename using current time
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    ostringstream oss;
    oss << prefix << "_" << put_time(localTime, "%Y%m%d_%H%M%S") << ".txt";
    return oss.str();
}

void Save::appendToFile(const std::string& filename,const std::string& data) {
    ofstream outputFile(filename, ios::app); 
    if (outputFile.is_open()) {
        outputFile << data << endl;
        outputFile.close();
    } else {
        cerr << "Unable to open file " << filename << " for writing." << endl;
    }
}
void Save::saveCharacter(Character& character,const std::string& characterType) {
    string filename = generateFilename("CharacterData");
    string data = characterType + ": Health is: " + to_string(character.get_health()) + ", Is Alive: " + (character.get_isAlive() ? "Yes" : "No");
    appendToFile(filename, data);
}

void Save::saveMinion(Minion& minion) {
    string filename = generateFilename("CharacterData");
    string data = "Minion: Health: " + to_string(minion.get_health()) + ", Is Alive: " + (minion.get_isAlive() ? "Yes" : "No");
    appendToFile(filename, data);
}

void Save::saveMiniBoss(MiniBoss& miniBoss) {
    string filename = generateFilename("CharacterData");
    string data = "MiniBoss: Health: " + to_string(miniBoss.get_health()) + ", Is Alive: " + (miniBoss.get_isAlive() ? "Yes" : "No");
    appendToFile(filename, data);
}

void Save::saveBoss(Boss& boss) {
    string filename = generateFilename("CharacterData");
    string data = "Boss: Health: " + to_string(boss.get_health()) + ", Is Alive: " + (boss.get_isAlive() ? "Yes" : "No");
    appendToFile(filename, data);
}

void Save::loadCharacter(Fighter& fighter, Wizard& wizard, Cleric& cleric, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to open file " << filename << " for reading." << endl;
        return;
    }
    string characterType;
    int health;
    cout << "Reading character data from " << filename << endl;
    while (inputFile >> characterType >> health) {
        cout << "Read characterType: " << characterType << ", health: " << health << endl;
        if (characterType == "Fighter") {
            fighter.set_health(health);
        } else if (characterType == "Wizard") {
            wizard.set_health(health);
        } else if (characterType == "Cleric") {
            cleric.set_health(health);
        }
    }
    inputFile.close();
}

void Save::loadMinions(Minion& minion, MiniBoss& miniBoss, Boss& boss, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Unable to open file " << filename << " for reading." << endl;
        return;
    }

    string monsterType;
    int health;
    string isAliveStr;
    bool isAlive;

    cout << "Reading minion data from " << filename << endl;

    while (inputFile >> monsterType >> health >> isAliveStr) {
        cout << "Read monsterType: " << monsterType << ", health: " << health << ", isAliveStr: " << isAliveStr << endl;
        isAlive = (isAliveStr == "Yes");
        if (monsterType == "Minion") {
            if (isAlive) {
                minion.set_health(100);
            }
        } else if (monsterType == "MiniBoss") {
            if (isAlive) {
                miniBoss.set_health(250);
            }
        } else if (monsterType == "Boss") {
            if (isAlive) {
                boss.set_health(500);
            }
        }
    }
    inputFile.close();
}
