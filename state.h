#ifndef state_h
#define state_h

namespace graphics
{
    class State
    {
        public:
        //this fucntion will initialise the state
        virtual void Init() = 0;
        //handles input of the player
        virtual void handleInput() = 0;
        //updates the screen 
        virtual void update(float dt) = 0;
        //draw the application, factoring in a frame rate dt
        virtual void Draw(float dt) = 0;
        //will be called when you pause the game
        virtual void Pause(){}
        //will be called when you resume the game
        virtual void Resume(){}
    };

}

#endif