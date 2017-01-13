#include <SFML/Graphics.hpp>
#include <list>
#include "MainMenu.h"
#include "Scene.h"
#include "MapSelector.h"
#include "Multiplayer.h"


Game::MainMenu Menu;
Game::MapSelector Selector;


int main()
{
    Menu.Start();
    if(Menu.Difficulty>=1&&Menu.Difficulty<=3)
    {
        Selector.Start();
        Game::Scene Scene;
        Scene.Start(Menu.Difficulty,Selector.SelectedMap,Menu.TankColor);
    }
    else if (Menu.Difficulty==99)
    {
        Selector.Start();
        Game::Multiplayer Scene;
        Scene.Start(Selector.SelectedMap,Menu.TankColor);
    }
    return 0;
}
