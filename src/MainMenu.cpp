#include "MainMenu.h"
namespace Game
{

MainMenu::MainMenu()
{
    //ctor
}

MainMenu::~MainMenu()
{
    //dtor
}
void MainMenu::Start()
{
    sf::RenderWindow window(sf::VideoMode(600,350), "Tanks! Boom Boom!");
    LoadTextures();
    Window = &window;
    BackgroundSprite.setPosition(sf::Vector2f(0,0));
    BoomSprite.setOrigin(sf::Vector2f(99,54));
    BoomSprite.setPosition(sf::Vector2f(190,250));
    BoomSprite.setRotation(-20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ButonsClicks();
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = BoomClock.restart();
        BoomTick+=elapsed.asSeconds()*3;
        MenuTick+=elapsed.asSeconds()*3;
        BoomSprite.setScale(lerp(0.75,1.25,abs(cos(BoomTick))),lerp(0.75,1.25,abs(cos(BoomTick))));
        window.clear();
        window.draw(BackgroundSprite);
        DrawMain();
        ButtonsHover();
        MenuAnimation();
        window.draw(BoomSprite);
        window.display();
    }
}


}
