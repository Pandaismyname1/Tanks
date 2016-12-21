#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Utils.h"
#include <iostream>
namespace Game
{
#ifndef TANK_H
#define TANK_H
    class Tank {
        public:
            Game::Map *WorldMap;
            Game::Utils *Utils;
            sf::Sprite *Sprite;
            int Life;
            int Damage;
            int X,Y;
            int Rotation;
            int TankControlType;
            float OneShotKillTimer;


            Tank();
            virtual ~Tank();
            bool init(int, int, int);
            void setPosition(int, int);
            bool Move();
            void RotateTo(int);
        };
    #endif // TANK_H
}
