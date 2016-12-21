#include "Tank.h"

namespace Game
{

    Tank::Tank()
    {
        //ctor
    }
    bool Tank::init(int NewX, int NewY , int Type)
    {
        X = NewX;
        Y = NewY;
        Damage = 1;
        Rotation =0;
        Life = 5;
        OneShotKillTimer = 0;
        TankControlType = Type;
        //Sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
        //Sprite->setScale(1.6);
        //Sprite->setPosition(cocos2d::Vec2((Y - 1) * 10, (X - 1) * 10));
        return true;
    }
    void Tank::setPosition(int NewX, int NewY)
    {
        X = NewX;
        Y = NewY;
        //Sprite->setPosition(cocos2d::Vec2((Y - 1) * 10, (X - 1) * 10));
    }
    bool Tank::Move()
    {
        std::cout<<X<<" "<<Y<<std::endl;
        if (Rotation == 0)
        {
            if (Utils->IsWalkableTile(WorldMap,X,Y+2)&&Utils->IsWalkableTile(WorldMap,X+1,Y+2))
            {
                setPosition(X,Y+1);
                return true;
            }
        }
        else if (Rotation == 90)
        {
            if (Utils->IsWalkableTile(WorldMap,X+2,Y)&&Utils->IsWalkableTile(WorldMap,X+2,Y+1))
            {
                setPosition(X+1,Y);
                return true;
            }
        }
        else if (Rotation == 180)
        {
            if (Utils->IsWalkableTile(WorldMap,X,Y-1)&&Utils->IsWalkableTile(WorldMap,X+1,Y-1))
            {
                setPosition(X, Y - 1);
                return true;
            }
        }
        else if (Rotation == 270)
        {
            if (Utils->IsWalkableTile(WorldMap,X-1,Y)&&Utils->IsWalkableTile(WorldMap,X-1,Y+1))
            {
                setPosition(X - 1, Y);
                return true;
            }
        }
        return false;
    }
    void Tank::RotateTo(int Angles)
    {
        Rotation += Angles;
        if(Rotation == 360) Rotation = 0;
        else if (Rotation == -90) Rotation = 270;
    }
    Tank::~Tank()
    {
        //dtor
    }

}
