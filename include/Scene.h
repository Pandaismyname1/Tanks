#include "Tank.h"
#include "AI_Base.h"
#include "AI_Player_Easy.h"
#include "AI_Player_Medium.h"
#include "AI_Player_Hard.h"
#include "Map.h"
#include "Tank.h"
#include "Utils.h"
#include <string>
namespace Game
{
#ifndef SCENE_H
#define SCENE_H


	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		Game::Map GameMap;
		std::list<Game::Tank*> TanksList;
		std::list<Game::Bullet> BulletList;
		std::list<Game::AI_Base*> AIList;
		Game::Tank Player;
		Game::Utils GameUtils;
		sf::Clock GameClock;
		sf::Sprite WorldSprite;
		sf::Sprite PlayerSprite;
		sf::Sprite BulletsSprite;
		sf::Texture WorldBuilder;
		sf::Texture WorldBases;
		sf::Texture Tanks;
		sf::Texture Bullet;
		sf::RenderWindow *Window;
		int WorldSpritePixels = 10;
		float Tick = 0;
		int AITanksSpawned = 0;
		int AISpawnTick;
		int PlayerColor = 5;
		float lerp(float a, float b, float f);
		void DrawBullets();
		void DetectInput();
		void LoadTextures();
		void DrawTanks();
		void SpawnPlayer();
		void DrawMap();
		void SpawnAI(int Dificulty);
		void Start(int Difficulty, std::string MapName);


	protected:

	private:
	};

#endif // SCENE_H
}
