#include "Tank.h"
#include "Map.h"
#include "Utils.h"
#include "Pickup.h"
#include <string>
#include <list>
namespace Game
{
#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H


class Multiplayer
{
    public:
        Multiplayer();
        virtual ~Multiplayer();

		Game::Map GameMap;
		std::list<Game::Pickup> PickupList;
		std::list<Game::Tank*> TanksList;
		std::list<Game::Bullet*> BulletList;
		Game::Tank Player1;
		Game::Tank Player2;
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
		sf::Texture Tanks;
		sf::Texture Bullet;
		sf::RenderWindow *Window;
		int WorldSpritePixels = 10;
		float Tick = 0;
		int PlayerColor = 5;
		int Winner=0;
		int NextPickup = 100;


		float lerp(float a, float b, float f);
		void DrawBullets();
		void DetectInput();
		void LoadTextures();
		void DrawTanks();
		void SpawnPlayers();
		void DrawMap();
		void CreatePickup();
		void DrawPickups();
		void Start(std::string MapName, int NewPlayerColor);

    protected:

    private:
};

#endif // MULTIPLAYER_H
}
