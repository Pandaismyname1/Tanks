#include "AI_Player_Medium.h"
namespace Game
{

	AI_Player_Medium::AI_Player_Medium()
	{
		//ctor
	}

	AI_Player_Medium::~AI_Player_Medium()
	{
		//dtor
	}

	void AI_Player_Medium::Tick()
	{
		tick += 1;
		if (alive)
		{
			if (tick % 3 == 0)
			{
				AITank->Move();
			}
			if (tick % 6 == 0)
			{
				AITank->Fire();
			}
			if (tick % 13 == 0)
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
			if (tick >= 100 && !AITank->TankCollision(AITank->TanksList, SpawnX, SpawnY))
			{
				tick = 0;
				Respawn();
			}
		}
	}
	void AI_Player_Medium::Respawn()
	{
		alive = true;
		AITank->X = SpawnX;
		AITank->Y = SpawnY;
		AITank->Life = 5;
		AITank->Damage = 1;
		AITank->OneShotKillTimer = 0;
	}

}
