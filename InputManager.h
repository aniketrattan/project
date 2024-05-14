#ifndef InputManager_h
#define InputManager_h
#include <SFML/Graphics.hpp>

namespace project {

class InputManager{
    private:

    public:
    //default constructor
    InputManager(){}
    ~InputManager(){}

    bool IsSpriteClicked (sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

    sf::Vector2i GetMOusePosition(sf::RenderWindow &window);
};

}

#endif