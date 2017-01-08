#include <SFML/Graphics.hpp>
#include <list>
#include "Map.h"
#include "Utils.h"
#include <iostream>
namespace Game
{
    #ifndef BULLET_H
    #define BULLET_H
    class Bullet
    {
        public:

            std::list<Game::Bullet> *BulletList;
            Game::Map *WorldMap;
            Game::Utils *Utils;
            int X,Y;
            int Rotation;
            int Damage;
            bool CanMove=true;

            Bullet();
            void Init(int NewX,int NewY,int NewRotation,int NewDamage,std::list<Game::Bullet> *Bullets,Game::Map *GameMap,Game::Utils *GameUtils);
            void Move();
            bool TryToExplode();
            void SetPosition(int, int);
            virtual ~Bullet();
            bool operator==( const Game::Bullet& other ) const
            {
                if(X==other.X&&Y==other.Y&&Rotation==other.Rotation)
                {
                    return true;
                }
                return false;
            }
};

#endif // BULLET_H

}
