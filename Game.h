#ifndef GAME_H
#define GAME_H

#include "Boss.h"
#include "Character.h"
#include "Cleric.h"
#include "Fighter.h"
#include "MiniBoss.h"
#include "Minion.h"
#include "Wizard.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

class Game {
private:
  // pointers to objects of the game
  Fighter *fighter;
  Wizard *wizard;
  Cleric *cleric;
  Minion *minion;
  MiniBoss *miniBoss;
  Boss *boss;
  int monsterCount = 1;

public:
  // default constructor
  Game();

  // setters
  void setMinion(Minion *minionPtr);
  void setMiniBoss(MiniBoss *miniBossPtr);
  void setBoss(Boss *bossPtr);
  void setFighter(Fighter *fighterPtr);
  void setWizard(Wizard *wizardPtr);
  void setCleric(Cleric *clericPtr);
  void setMonsterCount(int monsterCount);

  int getMonsterCount();
  void checkEndCondition(); // Declaration of the checkEndCondition function
  void loadGame(const std::string &filename);
  void round(); // Declaration of the round function
  ~Game();      // Destructor
};

#endif // GAME_H
