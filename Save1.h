#ifndef SAVE_H
#define SAVE_H

#include <fstream>
#include "Character.h"
#include "Minion.h"
#include "MiniBoss.h"
#include "Boss.h"
#include "Game.h"

class Save {
    std::string generateFilename(const std::string& prefix);
    void appendToFile(const std::string& filename,const std::string& data);
public:
    void saveCharacter(Character& character,const std::string& characterType);
    void saveMinion(Minion& minion);
    void saveMiniBoss(MiniBoss& miniBoss);
    void saveBoss(Boss& boss);
};

#endif 
