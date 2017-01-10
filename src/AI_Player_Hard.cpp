#include "AI_Player_Hard.h"
namespace Game
{

	AI_Player_Hard::AI_Player_Hard()
	{
		//ctor
	}

	AI_Player_Hard::~AI_Player_Hard()
	{
		//dtor
	}

	void AI_Player_Hard::Tick()
	{
		tick += 1;
		if (alive)
		{
			if (tick % 2 == 0)
			{
				AITank->Move();
			}
			if (tick % 4 == 0)
			{
				AITank->Fire();
			}
			if (tick % 7 == 0)
			{
				int randNum = rand() % (4);
				AITank->RotateTo(randNum * 90);
			}
			if (tick >= 1000)
			{
				tick -= 1000;
			}
			if (AITank->Life <= 0)
			{
				tick = 0;
				alive = false;
				AITank->X = 99;
				AITank->Y = 99;
			}
		}
		else
		{
			if (tick >= 50 && !AITank->TankCollision(AITank->TanksList, SpawnX, SpawnY))
			{
				tick = 0;
				Respawn();
			}
		}
	}
	void AI_Player_Hard::Respawn()
	{
		alive = true;
		AITank->X = SpawnX;
		AITank->Y = SpawnY;
		AITank->Life = 5;
		AITank->Damage = 1;
		AITank->OneShotKillTimer = 0;
	}

}
