#include "Scene.h"
namespace Game
{
	Scene::Scene()
	{
		//ctor
	}

	Scene::~Scene()
	{
		//dtor
	}
	void Scene::SpawnAI(int Dificulty)
	{
		for (int i = 0; i < GameMap.Height; i++)
		{
			for (int j = 0; j < GameMap.Width; j++)
			{
				if (GameMap.Matrix[j][i] == '$'&&GameMap.Matrix[j + 1][i] == '$'&&GameMap.Matrix[j][i + 1] == '$'&&GameMap.Matrix[j + 1][i + 1] == '$')
				{
					if (Dificulty == 1)
					{
						if (!Player.TankCollision(&TanksList, j, i) && !Player.TankCollision(&TanksList, j + 1, i) && !Player.TankCollision(&TanksList, j, i + 1) && !Player.TankCollision(&TanksList, j + 1, i + 1))
						{
							Game::AI_Player_Easy *AI = new Game::AI_Player_Easy();
							AI->SpawnX = j;
							AI->SpawnY = i;
							AI->AITank = new Game::Tank();
							AI->AITank->Init(j, i, 0, Dificulty, 2, 1, &BulletList, &TanksList,&PickupList, &GameMap, &GameUtils);
							AI->AITank->TankControlType = 1;
							TanksList.push_front(AI->AITank);
							AIList.push_front(AI);
							AITanksSpawned++;
						}
					}
					else if (Dificulty == 2)
					{
						if (!Player.TankCollision(&TanksList, j, i) && !Player.TankCollision(&TanksList, j + 1, i) && !Player.TankCollision(&TanksList, j, i + 1) && !Player.TankCollision(&TanksList, j + 1, i + 1))
						{
							Game::AI_Player_Medium *AI = new Game::AI_Player_Medium();
							AI->SpawnX = j;
							AI->SpawnY = i;
							AI->AITank = new Game::Tank();
							std::cout << j << " " << i;
							AI->AITank->Init(j, i, 0, Dificulty, 4, 1, &BulletList, &TanksList,&PickupList, &GameMap, &GameUtils);
							AI->AITank->TankControlType = 1;
							TanksList.push_front(AI->AITank);
							AIList.push_front(AI);
							AITanksSpawned++;
						}
					}
					else if (Dificulty == 3)
					{
						if (!Player.TankCollision(&TanksList, j, i) && !Player.TankCollision(&TanksList, j + 1, i) && !Player.TankCollision(&TanksList, j, i + 1) && !Player.TankCollision(&TanksList, j + 1, i + 1))
						{
							Game::AI_Player_Hard *AI = new Game::AI_Player_Hard();
							AI->SpawnX = j;
							AI->SpawnY = i;
							AI->AITank = new Game::Tank();
							std::cout << j << " " << i;
							AI->AITank->Init(j, i, 0, Dificulty, 5, 2, &BulletList, &TanksList,&PickupList, &GameMap, &GameUtils);
							AI->AITank->TankControlType = 1;
							TanksList.push_front(AI->AITank);
							AIList.push_front(AI);
							AITanksSpawned++;
						}
					}
				}
			}
		}
	}
	void Scene::DrawMap()
	{
		PlayerSprite.setOrigin(10, 10);
		for (int i = 0; i < GameMap.Width; i++)
		{
			for (int j = 0; j < GameMap.Height; j++)
			{
				if (GameMap.Matrix[i][j] == '#')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBuilder);
					WorldSprite.setTextureRect(sf::IntRect(0 * WorldSpritePixels, 0, WorldSpritePixels, WorldSpritePixels));
					Window->draw(WorldSprite);
				}
				else if (GameMap.Matrix[i][j] == '1')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBuilder);
					WorldSprite.setTextureRect(sf::IntRect(1 * WorldSpritePixels, 0, WorldSpritePixels, WorldSpritePixels));
					Window->draw(WorldSprite);
				}
				else if (GameMap.Matrix[i][j] == '2')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBuilder);
					WorldSprite.setTextureRect(sf::IntRect(2 * WorldSpritePixels, 0, WorldSpritePixels, WorldSpritePixels));
					Window->draw(WorldSprite);
				}
				else if (GameMap.Matrix[i][j] == '3')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBuilder);
					WorldSprite.setTextureRect(sf::IntRect(3 * WorldSpritePixels, 0, WorldSpritePixels, WorldSpritePixels));
					Window->draw(WorldSprite);
				}
				else if (GameMap.Matrix[i][j] == '0'||GameMap.Matrix[i][j] == '^'||GameMap.Matrix[i][j] == '$')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBuilder);
					WorldSprite.setTextureRect(sf::IntRect(4 * WorldSpritePixels, 0, WorldSpritePixels, WorldSpritePixels));
					Window->draw(WorldSprite);
				}
				else if (GameMap.Matrix[i][j] == '%'&&GameMap.Matrix[i + 1][j] == '%'&&GameMap.Matrix[i][j + 1] == '%'&&GameMap.Matrix[i + 1][j + 1] == '%')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBases);
					WorldSprite.setTextureRect(sf::IntRect(0 * WorldSpritePixels * 2, 0, WorldSpritePixels * 2, WorldSpritePixels * 2));
					Window->draw(WorldSprite);
				}
			}
		}
	}
	void Scene::SpawnPlayer()
	{
		for (int i = 0; i < GameMap.Height; i++)
		{
			for (int j = 0; j < GameMap.Width; j++)
			{
				if (GameMap.Matrix[j][i] == '^'&&GameMap.Matrix[j + 1][i] == '^'&&GameMap.Matrix[j][i + 1] == '^'&&GameMap.Matrix[j + 1][i + 1] == '^')
				{
					Player.Init(j, i, 0, PlayerColor, 5, 1, &BulletList, &TanksList,&PickupList, &GameMap, &GameUtils);
					TanksList.push_front(&Player);
				}
			}
		}
	}
	void Scene::DrawTanks()
	{
		std::list<Game::Tank*>::iterator i;
		for (i = TanksList.begin(); i != TanksList.end(); ++i)
		{
			PlayerSprite.setPosition(sf::Vector2f(((*i)->Y + 1) * 10, ((*i)->X + 1) * 10));
			PlayerSprite.setOrigin(10, 10);
			PlayerSprite.setRotation((*i)->Rotation);
			PlayerSprite.setTexture(Tanks);
			PlayerSprite.setTextureRect(sf::IntRect(1 * WorldSpritePixels * 2, (*i)->Color * 20, WorldSpritePixels * 2, WorldSpritePixels * 2));
			Window->draw(PlayerSprite);
		}
	}
	void Scene::LoadTextures()
	{
		WorldBuilder.loadFromFile("Resources/Sprites/WorldBuilder.png");
		WorldBases.loadFromFile("Resources/Sprites/WorldBases.png");
		Tanks.loadFromFile("Resources/Sprites/Tanks.png");
		Bullet.loadFromFile("Resources/Sprites/Bullet.png");
		Powerups.loadFromFile("Resources/Sprites/PowerUps.png");
		TextFont.loadFromFile("Resources/Fonts/Dimitri.TTF");
		Text.setCharacterSize(20);
		Text.setFont(TextFont);
        Text.setString("GameOver");
	}
	void Scene::DetectInput()
	{
		if (GameUtils.DetectInput() == 'W')
		{
			Player.Rotation = 270;
			Player.Move();
		}
		else if (GameUtils.DetectInput() == 'A')
		{
			Player.Rotation = 180;
			Player.Move();
		}
		else if (GameUtils.DetectInput() == 'D')
		{
			Player.Rotation = 0;
			Player.Move();
		}
		else if (GameUtils.DetectInput() == 'S')
		{
			Player.Rotation = 90;
			Player.Move();
		}
		else if (GameUtils.DetectInput() == ' ')
		{
			Player.Fire();
		}
	}
	void Scene::DrawBullets()
	{
		std::list<Game::Bullet*>::iterator i;
		for (i = BulletList.begin(); i != BulletList.end(); ++i)
		{
			BulletsSprite.setPosition(sf::Vector2f(((*i)->Y + 1) * 10, ((*i)->X + 1) * 10));
			BulletsSprite.setOrigin(10, 10);
			BulletsSprite.setRotation((*i)->Rotation);
			BulletsSprite.setTexture(Bullet);
			Window->draw(BulletsSprite);
		}
	}
	void Scene::CreatePickup()
	{
        Pickup NewPickup;
        srand(time(0));
        NewPickup.X = rand()%(GameMap.Width-4)+2;
        srand(time(0));
        NewPickup.Y = rand()%(GameMap.Height-4)+2;
        srand(time(0));
        NewPickup.Type = rand()%3;
        PickupList.push_back(NewPickup);
        std::cout<<NewPickup.X<<" "<<NewPickup.Y<<std::endl;
	}
	void Scene::DrawPickups()
	{
        std::list<Game::Pickup>::iterator i;
		for (i = PickupList.begin(); i != PickupList.end(); ++i)
		{
			PowerupsSprite.setPosition(sf::Vector2f(((*i).Y) * 10, ((*i).X) * 10));
			PowerupsSprite.setTexture(Powerups);
			PowerupsSprite.setTextureRect(sf::IntRect( (*i).Type*WorldSpritePixels*2, 0, WorldSpritePixels * 2, WorldSpritePixels * 2));
			Window->draw(PowerupsSprite);
		}
	}
	void Scene::Start(int Difficulty, std::string MapName, int NewPlayerColor)
	{
	    char ConvertedString[90];
	    strcpy(ConvertedString,MapName.c_str());
	    GameMap.Load(ConvertedString);
        GameUtils.InitInput();
	    PlayerColor = NewPlayerColor;
        sf::RenderWindow window(sf::VideoMode(GameMap.Height*WorldSpritePixels , GameMap.Width*WorldSpritePixels), "Tanks! Boom Boom!");
        Window = &window;
        window.setKeyRepeatEnabled(false);
        LoadTextures();
        SpawnPlayer();
        srand(time(0));
        SpawnAI(Difficulty);
        CreatePickup();

        while (Window->isOpen())
        {
            sf::Event event;
            GameUtils.GameEvent = &event;
            while (Window->pollEvent(event))
            {
                DetectInput();
                if (event.type == sf::Event::Closed)
                Window->close();
            }
            Window->clear();
            sf::Time elapsed = GameClock.restart();
            Tick+=elapsed.asSeconds();
            if(Tick>0.1)
            {
                srand(time(0));
                NextPickup--;
                if(NextPickup<=0)
                {
                    NextPickup+=100;
                    CreatePickup();
                }
                AISpawnTick++;
                if(AISpawnTick>=29&&AITanksSpawned<4)
                {
                    AISpawnTick-=29;
                    SpawnAI(Difficulty);
                }
                Tick=0;
                std::list<Game::Bullet*>::iterator i;
                for(i=BulletList.begin(); i != BulletList.end(); ++i)
                {
                    (*i)->Move();
                    if((*i)->TryToExplode()==true)
                    {
                        if(Player.Life<=0)
                        {
                            GameOver=true;
                        }
                        BulletList.remove(*i);
                    }
                    if(GameMap.Matrix[(*i)->X][(*i)->Y]=='%'||GameMap.Matrix[(*i)->X+1][(*i)->Y]=='%'||GameMap.Matrix[(*i)->X][(*i)->Y+1]=='%'||GameMap.Matrix[(*i)->X+1][(*i)->Y+1]=='%')
                    {
                        BaseHealth--;
                        BulletList.remove(*i);
                        if (BaseHealth<=0)
                        {
                            GameOver=true;
                        }
                    }
                }
                std::list<Game::AI_Base*>::iterator j;
                for(j=AIList.begin(); j != AIList.end(); ++j)
                {
                    (*j)->Tick();
                }
                std::list<Game::Tank*>::iterator k;
                for(k=TanksList.begin(); k != TanksList.end(); ++k)
                {
                    (*k)->CheckForBullets();
                    (*k)->CheckForPickups();
                    if((*k)->OneShotKillTimer>0)
                    {
                        (*k)->OneShotKillTimer-=0.1;
                    }
                    else if((*k)->OneShotKillTimer<0)
                    {
                        (*k)->OneShotKillTimer=0;
                    }
                }
                //Tick
            }
            if(!GameOver)
            {
            DrawMap();
            DrawTanks();
            DrawBullets();
            DrawPickups();
            }
            else
            {
                Window->draw(Text);
            }
            Window->display();
        }
	}
}
