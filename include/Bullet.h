#include <SFML/Graphics.hpp>
#include <list>
#include "Map.h"
#include "Utils.h"
namespace Game
{
    #ifndef BULLET_H
    #define BULLET_H
    class Bullet
    {
        public:

            std::list<Game::Bullet*> *BulletList;
            Game::Map *WorldMap;
            Game::Utils *Utils;
            int X=0,Y=0;
            int Rotation=0;
            int Damage;
            bool CanMove=true;

            Bullet();
            void Init(int NewX,int NewY,int NewRotation,int NewDamage,std::list<Game::Bullet*> *Bullets,Game::Map *GameMap,Game::Utils *GameUtils);
            void Move();
            bool TryToExplode();
            void SetPosition(int, int);
            virtual ~Bullet();

};

#endif // BULLET_H

}
