
#include "Multiplayer.h"
namespace Game
{

Multiplayer::Multiplayer()
{
    //ctor
}

Multiplayer::~Multiplayer()
{
    //dtor
}
	void Multiplayer::DrawMap()
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
				else if (GameMap.Matrix[i][j] == '0'||GameMap.Matrix[i][j] == '^'||GameMap.Matrix[i][j] == '$'||GameMap.Matrix[i][j] == '%')
				{
					WorldSprite.setPosition(sf::Vector2f(j * 10, i * 10));
					WorldSprite.setTexture(WorldBuilder);
					WorldSprite.setTextureRect(sf::IntRect(4 * WorldSpritePixels, 0, WorldSpritePixels, WorldSpritePixels));
					Window->draw(WorldSprite);
				}
			}
		}
	}
	void Multiplayer::SpawnPlayers()
	{
		for (int i = 0; i < GameMap.Height; i++)
		{
			for (int j = 0; j < GameMap.Width; j++)
			{
				if (GameMap.Matrix[j][i] == '^'&&GameMap.Matrix[j + 1][i] == '^'&&GameMap.Matrix[j][i + 1] == '^'&&GameMap.Matrix[j + 1][i + 1] == '^')
				{
					Player1.Init(j, i, 0, PlayerColor, 5, 1, &BulletList, &TanksList,&PickupList, &GameMap, &GameUtils);
					TanksList.push_front(&Player1);
				}
				if (GameMap.Matrix[j][i] == '$'&&GameMap.Matrix[j + 1][i] == '$'&&GameMap.Matrix[j][i + 1] == '$'&&GameMap.Matrix[j + 1][i + 1] == '$')
				{
					Player2.Init(j, i, 0, (PlayerColor + 1)%8, 5, 1, &BulletList, &TanksList,&PickupList, &GameMap, &GameUtils);
					TanksList.push_front(&Player2);
				}
			}
		}
	}
	void Multiplayer::DrawTanks()
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
	void Multiplayer::LoadTextures()
	{
		WorldBuilder.loadFromFile("Resources/Sprites/WorldBuilder.png");
		Tanks.loadFromFile("Resources/Sprites/Tanks.png");
		Bullet.loadFromFile("Resources/Sprites/Bullet.png");
		Powerups.loadFromFile("Resources/Sprites/PowerUps.png");
		TextFont.loadFromFile("Resources/Fonts/Dimitri.TTF");
		Text.setCharacterSize(20);
		Text.setFont(TextFont);
	}
	void Multiplayer::DetectInput()
	{
		if (GameUtils.DetectInput() == 'W')
		{
			Player1.Rotation = 270;
			Player1.Move();
		}
		else if (GameUtils.DetectInput() == 'A')
		{
			Player1.Rotation = 180;
			Player1.Move();
		}
		else if (GameUtils.DetectInput() == 'D')
		{
			Player1.Rotation = 0;
			Player1.Move();
		}
		else if (GameUtils.DetectInput() == 'S')
		{
			Player1.Rotation = 90;
			Player1.Move();
		}
		else if (GameUtils.DetectInput() == ' ')
		{
			Player1.Fire();
		}
		else if (GameUtils.DetectInput() == 'U')
		{
			Player2.Rotation = 270;
			Player2.Move();
		}
		else if (GameUtils.DetectInput() == 'H')
		{
			Player2.Rotation = 180;
			Player2.Move();
		}
		else if (GameUtils.DetectInput() == 'J')
		{
			Player2.Rotation = 0;
			Player2.Move();
		}
		else if (GameUtils.DetectInput() == 'K')
		{
			Player2.Rotation = 90;
			Player2.Move();
		}
		else if (GameUtils.DetectInput() == 8)
		{
			Player2.Fire();
		}
	}
	void Multiplayer::DrawBullets()
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
	void Multiplayer::CreatePickup()
	{
        Pickup NewPickup;
        srand(time(0));
        NewPickup.X = rand()%(GameMap.Width-4)+2;
        srand(time(0));
        NewPickup.Y = rand()%(GameMap.Height-4)+2;
        srand(time(0));
        NewPickup.Type = rand()%3;
        PickupList.push_back(NewPickup);
	}
	void Multiplayer::DrawPickups()
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
	void Multiplayer::Start(std::string MapName, int NewPlayerColor)
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
        SpawnPlayers();
        srand(time(0));
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
                Tick=0;
                srand(time(0));
                NextPickup--;
                if(NextPickup<=0)
                {
                    NextPickup+=100;
                    CreatePickup();
                }
                std::list<Game::Bullet*>::iterator i;
                for(i=BulletList.begin(); i != BulletList.end(); ++i)
                {
                    (*i)->Move();
                    if((*i)->TryToExplode()==true)
                    {
                        BulletList.remove(*i);
                    }
                    else if(GameMap.Matrix[(*i)->X][(*i)->Y]=='%'||GameMap.Matrix[(*i)->X+1][(*i)->Y]=='%'||GameMap.Matrix[(*i)->X][(*i)->Y+1]=='%'||GameMap.Matrix[(*i)->X+1][(*i)->Y+1]=='%')
                    {
                        BulletList.remove(*i);
                    }
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

            if(Player1.Life<=0)
            {
                Winner=2;
            }
            else if(Player2.Life<=0)
            {
                Winner=1;
            }
            if(Winner==0)
            {
            DrawMap();
            DrawTanks();
            DrawBullets();
            DrawPickups();
            }
            else if(Winner==1)
            {
                Text.setString("Player 1 Won!!!");
                Window->draw(Text);
            }
            else if(Winner==2)
            {
                Text.setString("Player 2 Won!!!");
                Window->draw(Text);
            }
            Window->display();
        }
	}

}
