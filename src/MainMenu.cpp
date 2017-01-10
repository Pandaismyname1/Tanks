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
		sf::RenderWindow window(sf::VideoMode(600, 350), "Tanks! Boom Boom!");
		LoadTextures();
		Window = &window;
		BackgroundSprite.setPosition(sf::Vector2f(0, 0));
		BoomSprite.setOrigin(sf::Vector2f(99, 54));
		BoomSprite.setPosition(sf::Vector2f(190, 250));
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
			BoomTick += elapsed.asSeconds() * 3;
			MenuTick += elapsed.asSeconds() * 3;
			BoomSprite.setScale(lerp(0.75, 1.25, abs(cos(BoomTick))), lerp(0.75, 1.25, abs(cos(BoomTick))));
			window.clear();
			window.draw(BackgroundSprite);
			DrawMain();
			ButtonsHover();
			MenuAnimation();
			window.draw(BoomSprite);
			window.display();
		}
	}
	void MainMenu::LoadTextures()
	{
		BackgroundTexture.loadFromFile("Resources/Sprites/MenuBackground.png");
		BackgroundSprite.setTexture(BackgroundTexture);
		BoomTexture.loadFromFile("Resources/Sprites/Boom.png");
		BoomSprite.setTexture(BoomTexture);
		UITexture.loadFromFile("Resources/Sprites/UI.png");
		UISprite.setTexture(UITexture);
		UIFont.loadFromFile("Resources/Fonts/Dimitri.ttf");
		UIText.setFont(UIFont);
		UIText.setCharacterSize(48);
	}
	void MainMenu::DrawMain()
	{
		UISprite.setColor(sf::Color(255, 255, 255, 255));
		UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 30));
		Window->draw(UISprite);

		UIText.setString("Play");
		UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 50, 25));
		UIText.setColor(sf::Color(100, 100, 100, 255));
		Window->draw(UIText);

		UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 90));
		Window->draw(UISprite);

		UIText.setString("Editor");
		UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 25, 85));
		Window->draw(UIText);

		UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 150));
		Window->draw(UISprite);

		UIText.setString("Options");
		UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 15, 145));
		Window->draw(UIText);

		UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 270));
		Window->draw(UISprite);

		UIText.setString("Quit");
		UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 50, 265));
		Window->draw(UIText);




		UISprite.setColor(sf::Color(95, 193, 95, 255));
		UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 30));
		Window->draw(UISprite);

		UIText.setString("Easy");
		UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 50, 25));
		UIText.setColor(sf::Color(40, 81, 40, 255));
		Window->draw(UIText);

		UISprite.setColor(sf::Color(193, 193, 95, 255));
		UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 90));
		Window->draw(UISprite);

		UIText.setString("Medium");
		UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 15, 85));
		UIText.setColor(sf::Color(79, 79, 30, 255));
		Window->draw(UIText);

		UISprite.setColor(sf::Color(193, 95, 95, 255));
		UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 150));
		Window->draw(UISprite);

		UIText.setString("Hard");
		UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 50, 145));
		UIText.setColor(sf::Color(79, 30, 30, 255));
		Window->draw(UIText);

		UISprite.setColor(sf::Color(255, 255, 255, 255));
		UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 270));
		Window->draw(UISprite);

		UIText.setString("Back");
		UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 50, 265));
		UIText.setColor(sf::Color(100, 100, 100, 255));
		Window->draw(UIText);

	}
	void MainMenu::ButonsClicks()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (showMenu == 0 || showMenu == 2))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 && mousePos.y>270 && mousePos.y<320)
			{
				Window->close();
			}
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 & mousePos.y>90 && mousePos.y<140)
			{
				//Editor
			}
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 & mousePos.y>150 && mousePos.y<200)
			{
				//Options
			}
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 && mousePos.y>30 && mousePos.y<80)
			{
				showMenu = 1;
				MenuTick = 0;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && showMenu == 1)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 && mousePos.y>270 && mousePos.y<320)
			{
				showMenu = 2;
				MenuTick = 0;
			}
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 & mousePos.y>150 && mousePos.y<200)
			{
				//Hard
				Difficulty = 3;
				Window->close();
			}
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 & mousePos.y>90 && mousePos.y<140)
			{
				//Medium
				Difficulty = 2;
				Window->close();
			}
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 && mousePos.y>30 && mousePos.y<80)
			{
				//Easy
				Difficulty = 1;
				Window->close();
			}
		}
	}
	void MainMenu::ButtonsHover()
	{
		if (showMenu == 0 || showMenu == 2)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 && mousePos.y>270 && mousePos.y<320)
			{
				UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 270));
				UISprite.setColor(sf::Color(200, 200, 200, 255));
				Window->draw(UISprite);
				UIText.setString("Quit");
				UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 50, 265));
				UIText.setColor(sf::Color(100, 100, 100, 255));
				Window->draw(UIText);
			}
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 && mousePos.y>90 && mousePos.y<140)
			{
				UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 90));
				UISprite.setColor(sf::Color(200, 200, 200, 255));
				Window->draw(UISprite);
				UIText.setString("Editor");
				UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 25, 85));
				UIText.setColor(sf::Color(100, 100, 100, 255));
				Window->draw(UIText);
			}
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 && mousePos.y>150 && mousePos.y<200)
			{
				UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 150));
				UISprite.setColor(sf::Color(200, 200, 200, 255));
				Window->draw(UISprite);
				UIText.setString("Options");
				UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 15, 145));
				UIText.setColor(sf::Color(100, 100, 100, 255));
				Window->draw(UIText);
			}
			if (mousePos.x>MainMenuButtonsX&&mousePos.x<MainMenuButtonsX + 200 && mousePos.y>30 && mousePos.y<80)
			{
				UISprite.setPosition(sf::Vector2f(MainMenuButtonsX, 30));
				UISprite.setColor(sf::Color(200, 200, 200, 255));
				Window->draw(UISprite);
				UIText.setString("Play");
				UIText.setPosition(sf::Vector2f(MainMenuButtonsX + 50, 25));
				UIText.setColor(sf::Color(100, 100, 100, 255));
				Window->draw(UIText);
			}
		}
		else if (showMenu == 1)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 && mousePos.y>270 && mousePos.y<320)
			{
				UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 270));
				UISprite.setColor(sf::Color(200, 200, 200, 255));
				Window->draw(UISprite);
				UIText.setString("Back");
				UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 50, 265));
				UIText.setColor(sf::Color(100, 100, 100, 255));
				Window->draw(UIText);
			}
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 && mousePos.y>90 && mousePos.y<140)
			{
				UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 90));
				UISprite.setColor(sf::Color(145, 145, 72, 255));
				Window->draw(UISprite);
				UIText.setString("Medium");
				UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 15, 85));
				UIText.setColor(sf::Color(79, 79, 30, 255));
				Window->draw(UIText);
			}
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 && mousePos.y>150 && mousePos.y<200)
			{
				UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 150));
				UISprite.setColor(sf::Color(145, 72, 72, 255));
				Window->draw(UISprite);
				UIText.setString("Hard");
				UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 50, 145));
				UIText.setColor(sf::Color(79, 30, 30, 255));
				Window->draw(UIText);
			}
			if (mousePos.x>PlayMenuButtonsX&&mousePos.x<PlayMenuButtonsX + 200 && mousePos.y>30 && mousePos.y<80)
			{
				UISprite.setPosition(sf::Vector2f(PlayMenuButtonsX, 30));
				UISprite.setColor(sf::Color(72, 145, 72, 255));
				Window->draw(UISprite);
				UIText.setString("Easy");
				UIText.setPosition(sf::Vector2f(PlayMenuButtonsX + 50, 25));
				UIText.setColor(sf::Color(30, 79, 30, 255));
				Window->draw(UIText);
			}
		}

	}
	void MainMenu::MenuAnimation()
	{
		if (showMenu == 1)
		{
			if (MenuTick<1)
			{
				MainMenuButtonsX = lerp(350, 600, MenuTick);
			}
			else if (MenuTick<2)
			{
				PlayMenuButtonsX = lerp(600, 350, MenuTick - 1);
			}
			else
			{
				MenuTick = 2;
			}
		}
		if (showMenu == 2)
		{
			if (MenuTick<1)
			{
				PlayMenuButtonsX = lerp(350, 600, MenuTick);
			}
			else if (MenuTick<2)
			{
				MainMenuButtonsX = lerp(600, 350, MenuTick - 1);
			}
			else
			{
				MenuTick = 2;
			}
		}
	}
	float MainMenu::lerp(float a, float b, float f)
	{
		return a + f * (b - a);
	}
	float MainMenu::abs(float a)
	{
		if (a >= 0)
		{
			return a;
		}
		return -a;
	}
}
