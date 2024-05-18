#include "GameGraphic.h"
#include "EncounterState.h"

graphics::GameGraphic::GameGraphic(int width, int height, string title) {
    //set the game window
  _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
  _data->machine.AddState(StateRef(new EncounterState(this->_data)));
  //runs the program
  this->Run(); 
}

void graphics::GameGraphic::Run() {
    float newTime;
    float frameTime;
    float interpolation;

    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumlator = 0.0f;

    while (this->_data->window.isOpen()){
        this->_data->machine.ProcessStateChanges();
        newTime = this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if (frameTime > 0.25f){
            frameTime = 0.25f;
        }
        currentTime = newTime;
        accumlator += frameTime;

        while(accumlator >= dt){
            this->_data->machine.GetActiveState()->handleInput();
            this->_data->machine.GetActiveState()->update(dt);
            accumlator -= dt;
        }
        interpolation = accumlator / dt;
        this->_data->machine.GetActiveState()->Draw(interpolation);
    }
}