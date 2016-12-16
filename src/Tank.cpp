#include "Tank.h"

namespace Game
{

    Tank::Tank()
    {
        //ctor
    }
    bool Tank::init(int X, int Y , int Type)
    {
        Position[0] = X;
        Position[1] = Y;
        Damage = 1;
        Direction =0;
        Life = 5;
        OneShotKillTimer = 0;
        TankControlType = Type;
        //Sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
        //Sprite->setScale(1.6);
        //Sprite->setPosition(cocos2d::Vec2((Y - 1) * 10, (X - 1) * 10));
        return true;
    }
    void Tank::setPosition(int X, int Y)
    {
        Position[0] = X;
        Position[1] = Y;
        //Sprite->setPosition(cocos2d::Vec2((Y - 1) * 10, (X - 1) * 10));
    }
    bool Tank::MoveForward()
    {
        if (Direction == 0)
        {
            if (WorldMap->Matrix[Position[0]][Position[1] + 1] == '0' || WorldMap->Matrix[Position[0]][Position[1] + 1] == '3')
            {
                setPosition(Position[0], Position[1] + 1);
                return true;
            }
        }
        else if (Direction == 1)
        {
            if (WorldMap->Matrix[Position[0] + 1][Position[1]] == '0' || WorldMap->Matrix[Position[0] + 1][Position[1]] == '3')
            {
                    setPosition(Position[0] + 1, Position[1]);
                return true;
            }
        }
        else if (Direction == 2)
        {
            if (WorldMap->Matrix[Position[0]][Position[1] - 1] == '0' || WorldMap->Matrix[Position[0]][Position[1] - 1] == '3')
            {
                setPosition(Position[0], Position[1] - 1);
                return true;
            }
        }
        else if (Direction == 3)
        {
            if (WorldMap->Matrix[Position[0] - 1][Position[1]] == '0' || WorldMap->Matrix[Position[0] - 1][Position[1]] == '3')
            {
                setPosition(Position[0] - 1, Position[1]);
                return true;
            }
        }
        return false;
    }
    void Tank::RotateTo(int Rotation)
    {
        Direction = Rotation;
    }
    Tank::~Tank()
    {
        //dtor
    }

}
