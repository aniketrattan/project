#include "GameGraphic.h"

#include "MapState.h"

graphics::GameGraphic::GameGraphic(int width, int height, string title) {
  // resets items
  std::ofstream writeFileBlade(SAVE_BLADE_FILE);

  if (writeFileBlade.is_open()) {
    writeFileBlade << 0;
  }

  writeFileBlade.close();

  std::ofstream writeFileRing(SAVE_RING_FILE);

  if (writeFileRing.is_open()) {
    writeFileRing << 0;
  }

  writeFileRing.close();

  std::ofstream writeFileWater(SAVE_WATER_FILE);

  if (writeFileWater.is_open()) {
    writeFileWater << 0;
  }

  writeFileWater.close();

  std::ofstream writeFileLife(SAVE_LIFE_FILE);

  if (writeFileLife.is_open()) {
    writeFileLife << 0;
  }

  writeFileLife.close();

  std::ofstream writeFileBoost(SAVE_BOOST_FILE);

  if (writeFileBoost.is_open()) {
    writeFileBoost << 0;
  }

  writeFileBoost.close();

  std::ofstream writeFileChance(SAVE_CHANCE_FILE);

  if (writeFileChance.is_open()) {
    writeFileChance << 0;
  }

  writeFileChance.close();
  // set the game window
  _data->window.create(sf::VideoMode(width, height), title,
                       sf::Style::Close | sf::Style::Titlebar);
  _data->machine.AddState(StateRef(new MapState(this->_data)));
  // runs the program
  this->Run();
}

void graphics::GameGraphic::Run() {
  float newTime;
  float frameTime;
  float interpolation;

  float currentTime = this->_clock.getElapsedTime().asSeconds();
  float accumlator = 0.0f;

  while (this->_data->window.isOpen()) {
    this->_data->machine.ProcessStateChanges();
    newTime = this->_clock.getElapsedTime().asSeconds();
    frameTime = newTime - currentTime;

    if (frameTime > 0.25f) {
      frameTime = 0.25f;
    }
    currentTime = newTime;
    accumlator += frameTime;

    while (accumlator >= dt) {
      this->_data->machine.GetActiveState()->handleInput();
      this->_data->machine.GetActiveState()->update(dt);
      accumlator -= dt;
    }
    interpolation = accumlator / dt;
    this->_data->machine.GetActiveState()->Draw(interpolation);
  }
}