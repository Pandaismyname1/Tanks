#include <SFML/Graphics.hpp>
#include <list>
#include "Map.h"
#include "Utils.h"
#include "Bullet.h"
#include <iostream>
namespace Game
{
#ifndef TANK_H
#define TANK_H
    class Tank {
        public:
            std::list<Game::Bullet> *BulletList;
            Game::Map *WorldMap;
            Game::Utils *Utils;
            int ID;
            int Life = 5;
            int Damage = 1;
            int X,Y;
            int Rotation = 0;
            int TankControlType = 0;
            float OneShotKillTimer;


            Tank();
            virtual ~Tank();
            void Init(int NewX, int NewY, int Type, std::list<Game::Bullet> *Bullets,Game::Map *Map,Game::Utils *GameUtils);
            void SetPosition(int, int);
            void Fire();
            void CheckForBullets();
            void Move();
            void RotateTo(int);
        };
    #endif // TANK_H
}
