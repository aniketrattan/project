#ifndef AssetManager_h
#define AssetManager_h

#include <map>

#include <SFML/Graphics.hpp>

using namespace std;

namespace project {
    class AssetManager{
        private:
        map<string, sf::Texture> _textures;
        map<string, sf::Font> _fonts;

        public:
        //constructor and deconstructor
        AssetManager(){}
        ~AssetManager(){}
        //program to load textures from a file on the computor
        void LoadTexture(string name, string fileName);
        //allows to get a particular textures reference
        sf::Texture &GetTexture(string name);

        //program to load fonts from a file on the computor
        void LoadFont(string name, string fileName);
        //allows to get a particular font reference
        sf::Font &GetFont(string name);
    };




}

#endif