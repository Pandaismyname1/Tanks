#include <SFML/Graphics.hpp>
#include <list>
#include "Map.h"
#include "Bullet.h"
#include "Utils.h"
#include "Pickup.h"
namespace Game
{
#ifndef TANK_H
#define TANK_H
    class Tank {
        public:
            std::list<Game::Bullet*> *BulletList;
            std::list<Game::Tank*> *TanksList;
            std::list<Game::Pickup> *PickupList;
            Game::Map *WorldMap;
            Game::Utils *Utils;
            int ID=0;
            int Life = 5;
            int Damage = 1;
            int X=0,Y=0;
            int Rotation = 0;
            int TankControlType = 0;
            float OneShotKillTimer=0;
            int Color=0;


            Tank();
            virtual ~Tank();
            void Init(int NewX, int NewY, int Type, int NewColor, int NewLife, int NewDamage, std::list<Game::Bullet*> *Bullets, std::list<Game::Tank*> *Tanks, std::list<Game::Pickup> *Pickups,Game::Map *Map,Game::Utils *GameUtils);
            void SetPosition(int, int);
            void Fire();
            void CheckForBullets();
            void CheckForPickups();
            bool TankCollision(std::list<Game::Tank*> *TankList, int X, int Y);
            void Move();
            void RotateTo(int);
        };
    #endif // TANK_H
}
