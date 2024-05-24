#include "ShopState.h"

#include <fstream>

#include "Definitions.h"

namespace graphics {

ShopState::ShopState(GameDataRef data) : _data(data) {}

void ShopState::Init() {
  this->_data->assets.LoadTexture("Shop Background", SHOP_BACKGROUND_FILEPATH);
  this->_data->assets.LoadFont("menu", GAME_FONT);
  _background.setTexture(this->_data->assets.GetTexture("Shop Background"));
  _menuItems = new MenuDisplay(_data, items);
  _menuUpper = new ShopUpper(_data, upper, money);
  _ItemDescription = new DescriptionDisplay(_data, descriptions,
                                            _menuItems->Get_Text(), 20, 50);
  _ItemDescriptionLast = new DescriptionDisplay(_data, descriptions,
                                                _menuItems->Get_Text(), 40, 90);
  _bought.resize(6);
  // to ensure that it doesn't start with any values of items

  for (int i = 7; i < 13; i++) {
    _bought[_boughtItems] = i;
    _boughtItems += 1;
  }

  // resets bought
  _boughtItems = 0;

  std::ifstream readFileBlade;
  readFileBlade.open(SAVE_BLADE_FILE);
  if (readFileBlade.is_open()) {
    while (!readFileBlade.eof()) {
      readFileBlade >> fileItems[0];
    }
  }

  readFileBlade.close();

  std::ifstream readFileRing;
  readFileRing.open(SAVE_RING_FILE);
  if (readFileRing.is_open()) {
    while (!readFileRing.eof()) {
      readFileRing >> fileItems[1];
    }
  }

  readFileRing.close();

  std::ifstream readFileWater;
  readFileWater.open(SAVE_WATER_FILE);
  if (readFileWater.is_open()) {
    while (!readFileWater.eof()) {
      readFileWater >> fileItems[2];
    }
  }

  readFileWater.close();

  std::ifstream readFileLife;
  readFileLife.open(SAVE_LIFE_FILE);
  if (readFileLife.is_open()) {
    while (!readFileLife.eof()) {
      readFileLife >> fileItems[3];
    }
  }

  readFileLife.close();

  std::ifstream readFileBoost;
  readFileBoost.open(SAVE_BOOST_FILE);
  if (readFileBoost.is_open()) {
    while (!readFileBoost.eof()) {
      readFileBoost >> fileItems[4];
    }
  }

  readFileBoost.close();

  std::ifstream readFileChance;
  readFileChance.open(SAVE_CHANCE_FILE);
  if (readFileChance.is_open()) {
    while (!readFileChance.eof()) {
      readFileChance >> fileItems[5];
    }
  }

  readFileChance.close();

  for (int j = 0; j <6; j++){
    if (fileItems[j] == 1)
     _bought[j] = j;
  }

  // tells what index's of the menu vector should be drawn
  menuBeginning = 1;
  menuEnd = 6;
}

void ShopState::handleInput() {
  sf::Event event;

  while (_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      std::ofstream writeFile(SAVE_MONSTER_FILE);

      if (writeFile.is_open()) {
        writeFile << 1;
      }

      writeFile.close();
      _data->window.close();
    }
    if (event.type == (sf::Event::KeyPressed)) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        // buys the item
        if (shop.buyItem(c1[0], "Reaper's Blade")) {
          // takes money out of account
          money = c1->get_money();
          _menuUpper->Update(upper, money);
          // take item off of display
          _bought[_boughtItems] = 0;
          // writes it's been bought in the file
          std::ofstream writeFile(SAVE_BLADE_FILE);

          if (writeFile.is_open()) {
            writeFile << 1;
          }

          writeFile.close();

          _boughtItems += 1;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        // buys the item
        if (shop.buyItem(c2[0], "Ring of Fire")) {
          // takes money out of account
          money = c1->get_money();
          _menuUpper->Update(upper, money);
          // take item off of display
          _bought[_boughtItems] = 1;
          // writes it's been bought in the file
          std::ofstream writeFile(SAVE_RING_FILE);

          if (writeFile.is_open()) {
            writeFile << 1;
          }

          writeFile.close();
          _boughtItems += 1;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        // buys the item
        if (shop.buyItem(c3[0], "Holy Water")) {
          // takes money out of account
          money = c1->get_money();
          _menuUpper->Update(upper, money);
          // take item off of display
          _bought[_boughtItems] = 2;
          // writes it's been bought in the file
          std::ofstream writeFile(SAVE_WATER_FILE);

          if (writeFile.is_open()) {
            writeFile << 1;
          }

          writeFile.close();
          _boughtItems += 1;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        // buys the item
        if (shop.buyItem(c1[0], "Life Essence")) {
          // takes money out of account
          money = c1->get_money();
          _menuUpper->Update(upper, money);
          // take item off of display
          _bought[_boughtItems] = 3;
          // writes it's been bought in the file
          std::ofstream writeFile(SAVE_LIFE_FILE);

          if (writeFile.is_open()) {
            writeFile << 1;
          }

          writeFile.close();
          _boughtItems += 1;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
        // buys the item
        if (shop.buyItem(c1[0], "Action Boost")) {
          // takes money out of account
          money = c1->get_money();
          _menuUpper->Update(upper, money);
          // take item off of display
          _bought[_boughtItems] = 4;
          // writes it's been bought in the file
          std::ofstream writeFile(SAVE_BOOST_FILE);

          if (writeFile.is_open()) {
            writeFile << 1;
          }

          writeFile.close();
          _boughtItems += 1;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
        // buys the item
        if (shop.buyItem(c1[0], "Second Chance")) {
          // takes money out of account
          money = c1->get_money();
          _menuUpper->Update(upper, money);
          // take item off of display
          _bought[_boughtItems] = 5;
          // writes it's been bought in the file
          std::ofstream writeFile(SAVE_CHANCE_FILE);

          if (writeFile.is_open()) {
            writeFile << 1;
          }

          writeFile.close();
          _boughtItems += 1;
        }
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // transports to encounter
        _data->machine.AddState(StateRef(new EncounterState(this->_data)),
                                true);
      }
    }
  }
}

void ShopState::update(float dt) {}

void ShopState::Draw(float dt) {
  _data->window.clear();

  _data->window.draw(_background);

  _menuItems->Draw(menuBeginning, menuEnd, _bought);
  _menuUpper->Draw(0, 2);
  _ItemDescription->Draw(menuBeginning, menuEnd - 1, _bought);
  _ItemDescriptionLast->Draw(6, 6, _bought);

  _data->window.display();
}

}  // namespace graphics