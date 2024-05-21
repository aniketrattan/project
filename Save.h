#ifndef SAVE_H
#define SAVE_H

#include <fstream>
#include "Character.h"
#include "Minion.h"
#include "MiniBoss.h"
#include "Boss.h"
#include "Game.h"

class Save {
public:
    void saveCharacter(Character& character,std::string& filename);
    void saveMinion(Minion& minion,std::string& filename);
    void saveMiniBoss(MiniBoss& miniBoss,std::string& filename);
    void saveBoss(Boss& boss,std::string& filename);
};

#endif // SAVE_H
