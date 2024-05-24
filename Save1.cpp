#include "Save1.h"
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




