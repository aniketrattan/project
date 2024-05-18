#ifndef InputManager_h
#define InputManager_h
#include <SFML/Graphics.hpp>

namespace graphics {

class InputManager{
    private:

    public:
    //default constructor
    InputManager(){}
    ~InputManager(){}

    bool MenuKeypressed(sf::Keyboard::Key(key), sf::RenderWindow& window);

    sf::Vector2i GetMOusePosition(sf::RenderWindow &window);
};

}

#endif