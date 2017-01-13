#include "Tank.h"
#include "AI_Base.h"
#include "AI_Player_Easy.h"
#include "AI_Player_Medium.h"
#include "AI_Player_Hard.h"
#include "Map.h"
#include "Utils.h"
#include "Pickup.h"
#include <string>
#include <list>
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
		std::list<Game::Pickup> PickupList;
		std::list<Game::Tank*> TanksList;
		std::list<Game::Bullet*> BulletList;
		std::list<Game::AI_Base*> AIList;
		Game::Tank Player;
		Game::Utils GameUtils;
		sf::Clock GameClock;
		sf::Font TextFont;
		sf::Text Text;
		sf::Sprite WorldSprite;
		sf::Sprite PlayerSprite;
		sf::Sprite BulletsSprite;
		sf::Sprite PowerupsSprite;
		sf::Texture WorldBuilder;
		sf::Texture Powerups;
		sf::Texture WorldBases;
		sf::Texture Tanks;
		sf::Texture Bullet;
		sf::RenderWindow *Window;
		int WorldSpritePixels = 10;
		float Tick = 0;
		int AITanksSpawned = 0;
		int AISpawnTick;
		int PlayerColor = 5;
		int BaseHealth=3;
		bool GameOver=false;
		int NextPickup = 100;


		float lerp(float a, float b, float f);
		void DrawBullets();
		void DetectInput();
		void LoadTextures();
		void DrawTanks();
		void SpawnPlayer();
		void DrawMap();
		void SpawnAI(int Dificulty);
		void CreatePickup();
		void DrawPickups();
		void ShowGameOver();
		void Start(int Difficulty, std::string MapName, int NewPlayerColor);
	protected:

	private:
	};

#endif // SCENE_H
}
