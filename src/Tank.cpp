#include "Tank.h"

namespace Game
{

    Tank::Tank()
    {
    }
    void Tank::Init(int NewX, int NewY, int Type, std::list<Game::Bullet> *Bullets,Game::Map *Map,Game::Utils *GameUtils)
    {
        X = NewX;
        Y = NewY;
        TankControlType = Type;
        BulletList = Bullets;
        WorldMap = Map;
        Utils = GameUtils;
    }
    void Tank::SetPosition(int NewX, int NewY)
    {
        X = NewX;
        Y = NewY;
    }
    void Tank::Move()
    {
        if (Rotation == 0)
        {
            if (Utils->IsWalkableTile(WorldMap,X,Y+2)&&Utils->IsWalkableTile(WorldMap,X+1,Y+2))
            {
                SetPosition(X,Y+1);
            }
        }
        else if (Rotation == 90)
        {
            if (Utils->IsWalkableTile(WorldMap,X+2,Y)&&Utils->IsWalkableTile(WorldMap,X+2,Y+1))
            {
                SetPosition(X+1,Y);
            }
        }
        else if (Rotation == 180)
        {
            if (Utils->IsWalkableTile(WorldMap,X,Y-1)&&Utils->IsWalkableTile(WorldMap,X+1,Y-1))
            {
                SetPosition(X, Y - 1);
            }
        }
        else if (Rotation == 270)
        {
            if (Utils->IsWalkableTile(WorldMap,X-1,Y)&&Utils->IsWalkableTile(WorldMap,X-1,Y+1))
            {
                SetPosition(X - 1, Y);
            }
        }
    }
    void Tank::RotateTo(int Angles)
    {
        Rotation += Angles;
        if(Rotation == 360) Rotation = 0;
        else if (Rotation == -90) Rotation = 270;
    }
    void Tank::Fire()
    {
        Game::Bullet *Bull = new Game::Bullet();
        if(Rotation==270)
        {
            Bull->Init(X-2,Y+0,270,1,BulletList,WorldMap,Utils);
        }
        else if(Rotation==90)
        {
            Bull->Init(X+2,Y+0,90,1,BulletList,WorldMap,Utils);
        }
        else if(Rotation==180)
        {
            Bull->Init(X+0,Y-2,180,1,BulletList,WorldMap,Utils);
        }
        else if(Rotation==0)
        {
            Bull->Init(X,Y+2,0,1,BulletList,WorldMap,Utils);
        }
        BulletList->push_back(*Bull);
    }
    void Tank::CheckForBullets()
    {

    }
    Tank::~Tank()
    {
    }

}
