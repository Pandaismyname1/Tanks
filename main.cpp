#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Tank.h"
#include "Bullet.h"
#include "Utils.h"
#include <list>

Game::Map GameMap;
std::list<Game::Tank> TanksList;
std::list<Game::Bullet> BulletList;
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
float Tick=0;

void DrawMap()
{
    PlayerSprite.setOrigin(10,10);
    for(int i=0;i<GameMap.Height;i++)
        {
            for(int j=0;j<GameMap.Width;j++)
            {
                if(GameMap.Matrix[i][j]=='#')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(0*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(GameMap.Matrix[i][j]=='1')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(1*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(GameMap.Matrix[i][j]=='2')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(2*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(GameMap.Matrix[i][j]=='3')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(3*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(GameMap.Matrix[i][j]=='*'&&GameMap.Matrix[i+1][j]=='*'&&GameMap.Matrix[i][j+1]=='*'&&GameMap.Matrix[i+1][j+1]=='*')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBases);
                    WorldSprite.setTextureRect(sf::IntRect(0*WorldSpritePixels*2,0,WorldSpritePixels*2,WorldSpritePixels*2));
                    Window->draw(WorldSprite);
                }
                else if(GameMap.Matrix[i][j]=='%'&&GameMap.Matrix[i+1][j]=='%'&&GameMap.Matrix[i][j+1]=='%'&&GameMap.Matrix[i+1][j+1]=='%')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBases);
                    WorldSprite.setTextureRect(sf::IntRect(1*WorldSpritePixels*2,0,WorldSpritePixels*2,WorldSpritePixels*2));
                    Window->draw(WorldSprite);
                }
            }
        }
}
void SpawnPlayer()
{
    for(int i=0;i<GameMap.Height;i++)
    {
        for(int j=0;j<GameMap.Width;j++)
        {
            if(GameMap.Matrix[j][i]=='^'&&GameMap.Matrix[j+1][i]=='^'&&GameMap.Matrix[j][i+1]=='^'&&GameMap.Matrix[j+1][i+1]=='^')
            {
                Player.Init(j,i,0,&BulletList,&GameMap,&GameUtils);
                TanksList.push_front(Player);
            }
        }
    }
}
void DrawPlayer()
{
    PlayerSprite.setOrigin(10,10);
    PlayerSprite.setTexture(Tanks);
    PlayerSprite.setPosition(sf::Vector2f(Player.Y*10+10, Player.X*10+10));
    PlayerSprite.setRotation(Player.Rotation);
    PlayerSprite.setTextureRect(sf::IntRect(1*WorldSpritePixels*2,Player.TankControlType*20,WorldSpritePixels*2,WorldSpritePixels*2));
    Window->draw(PlayerSprite);
}
void LoadTextures()
{
    WorldBuilder.loadFromFile("Resources/Sprites/WorldBuilder.png");
    WorldBases.loadFromFile("Resources/Sprites/WorldBases.png");
    Tanks.loadFromFile("Resources/Sprites/Tanks.png");
    Bullet.loadFromFile("Resources/Sprites/Bullet.png");
}
void DetectInput()
{
    if (GameUtils.DetectInput()=='W')
    {
        Player.Rotation = 270;
        Player.Move();
    }
    else if (GameUtils.DetectInput()=='A')
    {
        Player.Rotation = 180;
        Player.Move();
    }
    else if (GameUtils.DetectInput()=='D')
    {
        Player.Rotation = 0;
        Player.Move();
    }
    else if (GameUtils.DetectInput()=='S')
    {
        Player.Rotation = 90;
        Player.Move();
    }
    else if (GameUtils.DetectInput()==' ')
    {
        Player.Fire();
    }
}
void DrawBullets()
{
    std::list<Game::Bullet>::iterator i;
    for(i=BulletList.begin(); i != BulletList.end(); ++i)
    {
        BulletsSprite.setPosition(sf::Vector2f(((*i).Y+1)*10, ((*i).X+1)*10));
        BulletsSprite.setOrigin(10,10);
        BulletsSprite.setRotation((*i).Rotation);
        BulletsSprite.setTexture(Bullet);
        Window->draw(BulletsSprite);
    }
}

int main()
{
    GameMap.Load("Map1");
    GameUtils.InitInput();
    sf::RenderWindow window(sf::VideoMode(GameMap.Height*WorldSpritePixels , GameMap.Width*WorldSpritePixels), "Tanks! Boom Boom!");
    Window = &window;
    window.setKeyRepeatEnabled(false);
    LoadTextures();
    SpawnPlayer();

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
            std::list<Game::Bullet>::iterator i;
            for(i=BulletList.begin(); i != BulletList.end(); ++i)
            {
                (*i).Move();
                if((*i).TryToExplode()==true)
                {
                    BulletList.remove(*i);
                }
            }
            //Tick
        }
        DrawMap();
        DrawPlayer();
        DrawBullets();
        //window.draw(shape);
        Window->display();
    }

    return 0;
}
