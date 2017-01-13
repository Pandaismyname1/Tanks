#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <fstream>
#include "Editor.h"
namespace Game
{

#ifndef MAINMENU_H
#define MAINMENU_H


class MainMenu
{
    public:
        MainMenu();
        virtual ~MainMenu();
        void Start();
        sf::RenderWindow *Window;
        sf::Clock BoomClock;
        sf::Texture BackgroundTexture;
        sf::Texture BoomTexture;
        sf::Texture UITexture;
        sf::Texture TankTexture;
        sf::Sprite BackgroundSprite;
        sf::Sprite BoomSprite;
        sf::Sprite UISprite;
        sf::Sprite TankSprite;
        sf::Text UIText;
        sf::Font UIFont;
        int TankColor;
        int MainMenuButtonsX = 350;
        int PlayMenuButtonsX = 700;
        float BoomTick = 0;
        float MenuTick = 0;
        int showMenu = 0;
        int Difficulty = 0;
        void LoadTextures();
        void DrawMain();
        void ButonsClicks();
        void ButtonsHover();
        void MenuAnimation();
        float lerp(float a, float b, float f);
        float abs(float a);
        void SavePrefs();
        void LoadPrefs();
    protected:

    private:
};

#endif // MAINMENU_H
}
