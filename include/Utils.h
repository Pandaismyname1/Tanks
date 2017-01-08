#include <SFML/Graphics.hpp>
#include "Map.h"
namespace Game
{

    #ifndef UTILS_H
    #define UTILS_H
    class Utils
    {
        public:
            sf::Event *GameEvent;
            bool KeyPressed[];
            bool IsWalkableTile(Game::Map *map,int X,int Y);
            bool IsFlyableTile(Game::Map *map,int X, int Y);
            bool CanExplode(Game::Map *map,int X,int Y);
            bool ShouldExplode(Game::Map *map,int X, int Y);
            void InitInput();
            char DetectInput();
    };

    #endif // UTILS_H
}
