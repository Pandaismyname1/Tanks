#include "Bullet.h"
namespace Game
{
	Bullet::Bullet()
	{

	}
	void Bullet::Init(int NewX, int NewY, int NewRotation, int NewDamage, std::list<Game::Bullet> *Bullets, Game::Map *GameMap, Game::Utils *GameUtils)
	{
		X = NewX;
		Y = NewY;
		Rotation = NewRotation;
		Damage = NewDamage;
		BulletList = Bullets;
		WorldMap = GameMap;
		Utils = GameUtils;
	}
	bool Bullet::operator==(const Game::Bullet& other) const
	{
		if (X == other.X&&Y == other.Y&&Rotation == other.Rotation)
		{
			return true;
		}
		return false;
	}
	void Bullet::SetPosition(int NewX, int NewY)
	{
		X = NewX;
		Y = NewY;
		//Sprite->setPosition(cocos2d::Vec2((Y - 1) * 10, (X - 1) * 10));
	}
	bool Bullet::TryToExplode()
	{
		int k = 0;
		if (Utils->CanExplode(WorldMap, X, Y))
		{
			WorldMap->Matrix[X][Y] = '0';
			k++;
		}
		if (Utils->CanExplode(WorldMap, X + 1, Y))
		{
			WorldMap->Matrix[X + 1][Y] = '0';
			k++;
		}
		if (Utils->CanExplode(WorldMap, X, Y + 1))
		{
			WorldMap->Matrix[X][Y + 1] = '0';
			k++;
		}
		if (Utils->CanExplode(WorldMap, X + 1, Y + 1))
		{
			WorldMap->Matrix[X + 1][Y + 1] = '0';
			k++;
		}
		if (Utils->ShouldExplode(WorldMap, X, Y))
		{
			k++;
		}
		if (Utils->ShouldExplode(WorldMap, X + 1, Y))
		{
			k++;
		}
		if (Utils->ShouldExplode(WorldMap, X, Y + 1))
		{
			k++;
		}
		if (Utils->ShouldExplode(WorldMap, X + 1, Y + 1))
		{
			k++;
		}
		if (k > 0)
		{
			return true;
		}
		return false;
	}
	void Bullet::Move()
	{
		if (Rotation == 0)
		{
			if (Utils->IsFlyableTile(WorldMap, X, Y + 1) && Utils->IsFlyableTile(WorldMap, X + 1, Y + 1))
			{
				SetPosition(X, Y + 1);
			}
		}
		else if (Rotation == 90)
		{
			if (Utils->IsFlyableTile(WorldMap, X + 1, Y) && Utils->IsFlyableTile(WorldMap, X + 1, Y + 1))
			{
				SetPosition(X + 1, Y);
			}
		}
		else if (Rotation == 180)
		{
			if (Utils->IsFlyableTile(WorldMap, X, Y) && Utils->IsFlyableTile(WorldMap, X + 1, Y))
			{
				SetPosition(X, Y - 1);
			}
		}
		else if (Rotation == 270)
		{
			if (Utils->IsFlyableTile(WorldMap, X, Y) && Utils->IsFlyableTile(WorldMap, X, Y + 1))
			{
				SetPosition(X - 1, Y);
			}
		}
	}
	Bullet::~Bullet()
	{

	}
}
