#include <SFML/Graphics.hpp>
#include "Map.h"
namespace Game
{
#ifndef TANK_H
#define TANK_H
    class Tank {
        public:
            Game::Map *WorldMap;
            sf::Sprite *Sprite;
            int Life;
            int Damage;
            int Position[2];
            int Direction;
            int TankControlType;
            float OneShotKillTimer;


            Tank();
            virtual ~Tank();
            bool init(int, int, int);
            void setPosition(int, int);
            bool MoveForward();
            void RotateTo(int);
        };
    #endif // TANK_H
}
