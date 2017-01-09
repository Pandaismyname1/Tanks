#include <SFML/Graphics.hpp>
#include <list>
#include "Map.h"
#include "Bullet.h"
#include "Utils.h"
namespace Game
{
#ifndef TANK_H
#define TANK_H
    class Tank {
        public:
            std::list<Game::Bullet> *BulletList;
            std::list<Game::Tank*> *TanksList;
            Game::Map *WorldMap;
            Game::Utils *Utils;
            int ID;
            int Life = 5;
            int Damage = 1;
            int X,Y;
            int Rotation = 0;
            int TankControlType = 0;
            float OneShotKillTimer;
            int Color;


            Tank();
            virtual ~Tank();
            void Init(int NewX, int NewY, int Type, int NewColor, std::list<Game::Bullet> *Bullets, std::list<Game::Tank*> *Tanks,Game::Map *Map,Game::Utils *GameUtils);
            void SetPosition(int, int);
            void Fire();
            void CheckForBullets();
            bool TankCollision(std::list<Game::Tank*> *TankList, int X, int Y);
            void Move();
            void RotateTo(int);
        };
    #endif // TANK_H
}
