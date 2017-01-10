#include <SFML/Graphics.hpp>
#include <list>
#include "MainMenu.h"
#include "Scene.h"
#include "MapSelector.h"


Game::MainMenu Menu;
Game::MapSelector Selector;


int main()
{
    Menu.Start();
    if(Menu.Difficulty!=0)
    {
        Selector.Start();
        Game::Scene Scene;
        Scene.Start(Menu.Difficulty,Selector.SelectedMap);
    }
    return 0;
}
