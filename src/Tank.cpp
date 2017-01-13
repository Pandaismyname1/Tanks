#include "Tank.h"

namespace Game
{

	Tank::Tank()
	{
	}
	void Tank::Init(int NewX, int NewY, int Type, int NewColor, int NewLife, int NewDamage, std::list<Game::Bullet*> *Bullets, std::list<Game::Tank*> *Tanks, std::list<Game::Pickup> *Pickups, Game::Map *Map, Game::Utils *GameUtils)
	{
		X = NewX;
		Y = NewY;
		TankControlType = Type;
		BulletList = Bullets;
		TanksList = Tanks;
		WorldMap = Map;
		Utils = GameUtils;
		Color = NewColor;
		PickupList=Pickups;
		Life = NewLife;
		Damage = NewDamage;
	}
	void Tank::SetPosition(int NewX, int NewY)
	{
		X = NewX;
		Y = NewY;
	}
	bool Tank::TankCollision(std::list<Game::Tank*> *TankList, int X, int Y)
	{
		bool a = false;
		std::list<Game::Tank*>::iterator i;
		for (i = TankList->begin(); i != TankList->end(); ++i)
		{
			if (((*i)->X == X && (*i)->Y == Y))
			{
				a = true;
			}
		}
		return a;
	}
	void Tank::Move()
	{
		if (Rotation == 0)
		{
			if (Utils->IsWalkableTile(WorldMap, X, Y + 2) && Utils->IsWalkableTile(WorldMap, X + 1, Y + 2) && !TankCollision(TanksList, X, Y + 2) && !TankCollision(TanksList, X + 1, Y + 2) && !TankCollision(TanksList, X - 1, Y + 2))
			{
				SetPosition(X, Y + 1);
			}
		}
		else if (Rotation == 90)
		{
			if (Utils->IsWalkableTile(WorldMap, X + 2, Y) && Utils->IsWalkableTile(WorldMap, X + 2, Y + 1) && !TankCollision(TanksList, X + 2, Y) && !TankCollision(TanksList, X + 2, Y + 1) && !TankCollision(TanksList, X + 2, Y - 1))
			{
				SetPosition(X + 1, Y);
			}
		}
		else if (Rotation == 180)
		{
			if (Utils->IsWalkableTile(WorldMap, X, Y - 1) && Utils->IsWalkableTile(WorldMap, X + 1, Y - 1) && !TankCollision(TanksList, X, Y - 2) && !TankCollision(TanksList, X + 1, Y - 2) && !TankCollision(TanksList, X - 1, Y - 2))
			{
				SetPosition(X, Y - 1);
			}
		}
		else if (Rotation == 270)
		{
			if (Utils->IsWalkableTile(WorldMap, X - 1, Y) && Utils->IsWalkableTile(WorldMap, X - 1, Y + 1) && !TankCollision(TanksList, X - 2, Y) && !TankCollision(TanksList, X - 2, Y + 1) && !TankCollision(TanksList, X - 2, Y - 1))
			{
				SetPosition(X - 1, Y);
			}
		}
	}
	void Tank::RotateTo(int Angles)
	{
		Rotation += Angles;
		if (Rotation >= 360) Rotation -= 360;
		else if (Rotation < 0) Rotation += 360;
	}
	void Tank::Fire()
	{
		Game::Bullet *Bull = new Game::Bullet();
		if (Rotation == 270)
		{
            if(OneShotKillTimer>0)
            {
			Bull->Init(X - 2, Y + 0, 270, 999, BulletList, WorldMap, Utils);
            }
			else
            {
			Bull->Init(X - 2, Y + 0, 270, Damage, BulletList, WorldMap, Utils);
            }
		}
		else if (Rotation == 90)
		{
		    if(OneShotKillTimer>0)
            {
			Bull->Init(X + 2, Y + 0, 90, 999, BulletList, WorldMap, Utils);
            }
			else
            {
			Bull->Init(X + 2, Y + 0, 90, Damage, BulletList, WorldMap, Utils);
            }
		}
		else if (Rotation == 180)
		{
		    if(OneShotKillTimer>0)
            {
			Bull->Init(X + 0, Y - 2, 180, 999, BulletList, WorldMap, Utils);
            }
			else
            {
			Bull->Init(X + 0, Y - 2, 180, Damage, BulletList, WorldMap, Utils);
            }
		}
		else if (Rotation == 0)
		{
		    if(OneShotKillTimer>0)
            {
			Bull->Init(X, Y + 2, 0, 999, BulletList, WorldMap, Utils);
            }
			else
            {
			Bull->Init(X, Y + 2, 0, Damage, BulletList, WorldMap, Utils);
            }
		}
		BulletList->push_back(Bull);
	}
	void Tank::CheckForBullets()
	{
		std::list<Game::Bullet*>::iterator i;
		for (i = BulletList->begin(); i != BulletList->end(); ++i)
		{
			if (((*i)->X == X && (*i)->Y == Y) || ((*i)->X == X + 1 && (*i)->Y == Y) || ((*i)->X == X && (*i)->Y == Y + 1) || ((*i)->X == X + 1 && (*i)->Y == Y + 1) || ((*i)->X == X + 1 && (*i)->Y == Y - 1) || ((*i)->X == X && (*i)->Y == Y - 1) || ((*i)->X == X - 1 && (*i)->Y == Y - 1) || ((*i)->X == X - 1 && (*i)->Y == Y) || ((*i)->X == X - 1 && (*i)->Y == Y + 1))
			{
				Life -= (*i)->Damage;
				BulletList->remove(*i);
			}
		}
	}
	void Tank::CheckForPickups()
	{
		std::list<Game::Pickup>::iterator i;
		for (i = PickupList->begin(); i != PickupList->end(); ++i)
		{
			if (((*i).X == X && (*i).Y == Y) || ((*i).X == X + 1 && (*i).Y == Y) || ((*i).X == X && (*i).Y == Y + 1) || ((*i).X == X + 1 && (*i).Y == Y + 1) || ((*i).X == X + 1 && (*i).Y == Y - 1) || ((*i).X == X && (*i).Y == Y - 1) || ((*i).X == X - 1 && (*i).Y == Y - 1) || ((*i).X == X - 1 && (*i).Y == Y) || ((*i).X == X - 1 && (*i).Y == Y + 1))
			{
			    if((*i).Type==0)
                {
                    Life++;
                }
			    if((*i).Type==1)
                {
                    Damage++;
                }
			    if((*i).Type==2)
                {
                    OneShotKillTimer+=10;
                }
				PickupList->remove(*i);
			}
		}
	}
	Tank::~Tank()
	{
	}

}
