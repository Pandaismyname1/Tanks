#include <SFML/Graphics.hpp>
#include "Map.h"s
#include "Tank.h"

Game::Map Map;
Game::Tank Player;
sf::Sprite WorldSprite;
sf::Texture WorldBuilder;
sf::Texture WorldBases;
sf::Texture Tanks;
sf::RenderWindow *Window;
int WorldSpritePixels = 10;

void BuildMap()
{
    for(int i=0;i<Map.Width;i++)
        {
            for(int j=0;j<Map.Height;j++)
            {
                if(Map.Matrix[i][j]=='#')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(0*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(Map.Matrix[i][j]=='1')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(1*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(Map.Matrix[i][j]=='2')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(2*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(Map.Matrix[i][j]=='3')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBuilder);
                    WorldSprite.setTextureRect(sf::IntRect(3*WorldSpritePixels,0,WorldSpritePixels,WorldSpritePixels));
                    Window->draw(WorldSprite);
                }
                else if(Map.Matrix[i][j]=='*'&&Map.Matrix[i+1][j]=='*'&&Map.Matrix[i][j+1]=='*'&&Map.Matrix[i+1][j+1]=='*')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBases);
                    WorldSprite.setTextureRect(sf::IntRect(0*WorldSpritePixels*2,0,WorldSpritePixels*2,WorldSpritePixels*2));
                    Window->draw(WorldSprite);
                }
                else if(Map.Matrix[i][j]=='%'&&Map.Matrix[i+1][j]=='%'&&Map.Matrix[i][j+1]=='%'&&Map.Matrix[i+1][j+1]=='%')
                {
                    WorldSprite.setPosition(sf::Vector2f(j*10, i*10));
                    WorldSprite.setTexture(WorldBases);
                    WorldSprite.setTextureRect(sf::IntRect(1*WorldSpritePixels*2,0,WorldSpritePixels*2,WorldSpritePixels*2));
                    Window->draw(WorldSprite);
                }
            }
        }
}

int main()
{
    Map.Load("Map1");
    sf::RenderWindow window(sf::VideoMode(Map.Height*WorldSpritePixels , Map.Width*WorldSpritePixels), "Tanks! Boom Boom!");
    Window = &window;
    WorldBuilder.loadFromFile("Resources/Sprites/WorldBuilder.png");
    WorldBases.loadFromFile("Resources/Sprites/WorldBases.png");
    Tanks.loadFromFile("Resources/Sprites/Tanks.png");

    while (Window->isOpen())
    {
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
        }
        Window->clear();
        BuildMap();
        //window.draw(shape);
        Window->display();
    }

    return 0;
}
