#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Tank.h"
#include "Utils.h"

Game::Map GameMap;
Game::Tank Player;
Game::Utils GameUtils;
sf::Sprite WorldSprite;
sf::Sprite PlayerSprite;
sf::Texture WorldBuilder;
sf::Texture WorldBases;
sf::Texture Tanks;
sf::RenderWindow *Window;
int WorldSpritePixels = 10;

void BuildMap()
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
                Player.init(j,i,0);
                Player.Sprite = &PlayerSprite;
                Player.WorldMap = &GameMap;
                Player.Utils = &GameUtils;
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
        BuildMap();
        DrawPlayer();
        //window.draw(shape);
        Window->display();
    }

    return 0;
}
