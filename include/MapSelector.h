#include <SFML/Graphics.hpp>
#include <iostream>
#include <io.h>
#include <time.h>
#include <string>
#include <list>
namespace Game
{
    #ifndef MAPSELECTOR_H
    #define MAPSELECTOR_H


    class MapSelector
    {
        public:
            MapSelector();
            virtual ~MapSelector();
            std::string GetFileName(_finddata_t &data);
            std::list<std::string> Files;
            std::string SelectedMap="";
            sf::Font UIFont;
            sf::Text UIText;
            sf::Sprite BackgroundSprite;
            sf::Texture BackgroundTexture;
            sf::Sprite UISprite;
            sf::Texture UITexture;
            sf::RenderWindow *Window;
            void LoadFiles();
            void Draw();
            void ButtonsClick();
            void ButtonsHover();
            void Start();

        protected:

        private:
    };

    #endif // MAPSELECTOR_H
}
