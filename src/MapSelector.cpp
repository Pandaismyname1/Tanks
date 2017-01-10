#include "MapSelector.h"
namespace Game
{

    MapSelector::MapSelector()
    {
        //ctor
    }

    MapSelector::~MapSelector()
    {
        //dtor
    }
    std::string MapSelector::GetFileName(_finddata_t &data)
    {
        if ((data.attrib & _A_SUBDIR) != _A_SUBDIR)
        {
            return data.name;
        }
        return "";
    }
    void MapSelector::LoadFiles()
    {
        _finddata_t data;
        int ff = _findfirst ("Resources/Maps/*.*", &data);
        if (ff != -1)
        {
            int res = 0;
            while (res != -1)
            {
                std::string FileName = GetFileName(data);
                if (FileName!="")
                {
                    Files.push_back(FileName);
                }
                res = _findnext(ff, &data);
            }
            _findclose(ff);
        }
    }
    void MapSelector::Start()
    {
        LoadFiles();
		UIFont.loadFromFile("Resources/Fonts/Dimitri.ttf");
		BackgroundTexture.loadFromFile("Resources/Sprites/MapSelectorBackground.png");
		BackgroundSprite.setTexture(BackgroundTexture);
		UITexture.loadFromFile("Resources/Sprites/UI.png");
		UISprite.setTexture(UITexture);
		UIText.setFont(UIFont);
		UIText.setCharacterSize(20);
        sf::RenderWindow window(sf::VideoMode( 800, 600), "Tanks! Boom Boom!");
        Window = &window;
        while (Window->isOpen())
        {
            sf::Event event;
            while (Window->pollEvent(event))
            {
                ButtonsClick();
                if (event.type == sf::Event::Closed)
                Window->close();
            }
            Window->clear();
            Draw();
            ButtonsHover();
            Window->display();
        }
    }
    void MapSelector::Draw()
    {
        Window->draw(BackgroundSprite);
        UISprite.setColor(sf::Color(255,255,255,255));
        int x=0,y=0;
        std::list<std::string>::iterator i;
        for(i=Files.begin();i!=Files.end();++i)
        {
            UISprite.setPosition(x*210+30,y*60+30);
            Window->draw(UISprite);
            UIText.setString(*i);
            UIText.setPosition(sf::Vector2f(x*210+40, y*60+42));
            UIText.setColor(sf::Color(100, 100, 100, 255));
            Window->draw(UIText);
            y++;
            if(y>=9)
            {
                y=0;
                x++;
            }
        }
    }
    void MapSelector::ButtonsClick()
    {
        int x=0,y=0;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::list<std::string>::iterator i;
            for(i=Files.begin();i!=Files.end();++i)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
                if(mousePos.x>x*210+30&&mousePos.x<x*210+230&&mousePos.y>y*60+30&&mousePos.y<y*60+80)
                {
                    SelectedMap = (*i);
                    Window->close();
                }
                y++;
                if(y>=9)
                {
                    y=0;
                    x++;
                }
            }
        }
    }
    void MapSelector::ButtonsHover()
    {
        int x=0,y=0;
            std::list<std::string>::iterator i;
            for(i=Files.begin();i!=Files.end();++i)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
                if(mousePos.x>x*210+30&&mousePos.x<x*210+230&&mousePos.y>y*60+30&&mousePos.y<y*60+80)
                {
                    UISprite.setColor(sf::Color(200,200,200,255));
                    UISprite.setPosition(x*210+30,y*60+30);
                    Window->draw(UISprite);
                    UIText.setString(*i);
                    UIText.setPosition(sf::Vector2f(x*210+40, y*60+42));
                    UIText.setColor(sf::Color(100, 100, 100, 255));
                    Window->draw(UIText);
                }
            y++;
            if(y>=9)
            {
                y=0;
                x++;
            }
        }
    }
}
