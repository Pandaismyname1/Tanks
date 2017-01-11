#include "Editor.h"
namespace Game
{

	Editor::Editor()
	{
		//ctor
	}

	Editor::~Editor()
	{
		//dtor
	}
	void Editor::ExportMap(std::string NewFileName)
	{
		char ConvertedString[90];
		strcpy(ConvertedString, NewFileName.c_str());
		char str[80];
		strcpy(str, "Resources/Maps/");
		strcat(str, ConvertedString);
		std::ofstream file(str);
		file << Height << " " << Width << std::endl;
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				file << a[i][j];
			}
			file << std::endl;
		}
	}
	void Editor::NameMap()
	{
		sf::RenderWindow window(sf::VideoMode(300, 50), "Give it a name!");

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode >= 32 && event.text.unicode <= 126)
					{
						FileName += (char)event.text.unicode;
					}
					else if (event.text.unicode == 8 && FileName.size() > 0)
					{
						FileName.erase(FileName.size() - 1, FileName.size());
					}
					else if (event.text.unicode == 13 && FileName.size() > 0)
					{
						ExportMap(FileName);
						window.close();
					}
				}
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			UIText.setString(FileName);
			UIText.setColor(sf::Color(255, 255, 255, 255));
			UIText.setPosition(sf::Vector2f(0, 10));
			window.draw(UIText);
			window.display();
		}
	}
	void Editor::SetDimensions()
	{
		sf::RenderWindow window(sf::VideoMode(300, 50), "Please Insert Dimensions");
        bool setWidth=false;
        std::string SizeText;
        int SizeValue;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::TextEntered)
				{
                    if (event.text.unicode >= 48 && event.text.unicode <= 57)
					{
						SizeText += (char)event.text.unicode;
						std::stringstream(SizeText)>>SizeValue;
					}
					else if (event.text.unicode == 8 && SizeText.size() > 0)
					{
						SizeText.erase(SizeText.size() - 1, SizeText.size());
						//std::stringstream(SizeText)>>SizeValue;
					}
					else if (event.text.unicode == 13 && SizeText.size() > 0)
					{
					    SizeText = "";
					    if(setWidth)
                        {
                            window.close();
                            Height=SizeValue;
                        }
                        else
                        {
                            setWidth=true;
                            Width=SizeValue;
                        }
					}
				}
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			UIText.setString(SizeText);
			UIText.setColor(sf::Color(255, 255, 255, 255));
			UIText.setPosition(sf::Vector2f(0, 10));
			window.draw(UIText);
			window.display();
		}
	}
	void Editor::LoadTextures()
	{
		MaterialTexture.loadFromFile("Resources/Sprites/WorldBuilder.png");
		BlockSprite.setTexture(MaterialTexture);
		BaseTexture.loadFromFile("Resources/Sprites/WorldBases.png");
		UITexture.loadFromFile("Resources/Sprites/UI.png");
		UISprite.setTexture(UITexture);
		BaseSprite.setTexture(BaseTexture);
		UIFont.loadFromFile("Resources/Fonts/Dimitri.TTF");
		UIText.setFont(UIFont);
		UIText.setCharacterSize(20);
		UISprite.setScale(sf::Vector2f(0.5, 0.5));
		UISprite.setPosition(sf::Vector2f(0, 475));
	}
	void Editor::DrawBlocks()
	{
		BlockSprite.setScale(1, 1);
		for (int i = 0; i <= Height-1; i++)
		{
			for (int j = 0; j <= Width-1; j++)
			{
				if (a[i][j] == '0')
				{
					BlockSprite.setTextureRect(sf::IntRect(40, 0, 10, 10));
					BlockSprite.setPosition(sf::Vector2f(j * 10 + 100, i * 10));
					Window->draw(BlockSprite);
				}
				else if (a[i][j] == '#')
				{
					BlockSprite.setTextureRect(sf::IntRect(0, 0, 10, 10));
					BlockSprite.setPosition(sf::Vector2f(j * 10 + 100, i * 10));
					Window->draw(BlockSprite);
				}
				else if (a[i][j] == '1')
				{
					BlockSprite.setTextureRect(sf::IntRect(10, 0, 10, 10));
					BlockSprite.setPosition(sf::Vector2f(j * 10 + 100, i * 10));
					Window->draw(BlockSprite);
				}
				else if (a[i][j] == '2')
				{
					BlockSprite.setTextureRect(sf::IntRect(20, 0, 10, 10));
					BlockSprite.setPosition(sf::Vector2f(j * 10 + 100, i * 10));
					Window->draw(BlockSprite);
				}
				else if (a[i][j] == '3')
				{
					BlockSprite.setTextureRect(sf::IntRect(30, 0, 10, 10));
					BlockSprite.setPosition(sf::Vector2f(j * 10 + 100, i * 10));
					Window->draw(BlockSprite);
				}
				else if (a[i][j] == '%'&&a[i + 1][j] == '%'&&a[i][j + 1] == '%'&&a[i + 1][j + 1] == '%')
				{
					BaseSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
					BaseSprite.setPosition(sf::Vector2f(100 + j * 10, i * 10));
					BaseSprite.setScale(1, 1);
					Window->draw(BaseSprite);
				}
				else if (a[i][j] == '$'&&a[i + 1][j] == '$'&&a[i][j + 1] == '$'&&a[i + 1][j + 1] == '$')
				{
					BaseSprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
					BaseSprite.setPosition(sf::Vector2f(100 + j * 10, i * 10));
					BaseSprite.setScale(1, 1);
					Window->draw(BaseSprite);
				}
				else if (a[i][j] == '^'&&a[i + 1][j] == '^'&&a[i][j + 1] == '^'&&a[i + 1][j + 1] == '^')
				{
					BaseSprite.setTextureRect(sf::IntRect(40, 0, 20, 20));
					BaseSprite.setPosition(sf::Vector2f(100 + j * 10, i * 10));
					BaseSprite.setScale(1, 1);
					Window->draw(BaseSprite);
				}
			}
		}
	}
	void Editor::DrawPallete()
	{
		for (int i = 0; i < 5; i++)
		{
			BlockSprite.setScale(5, 5);
			BlockSprite.setTextureRect(sf::IntRect(i * 10, 0, 10, 10));
			BlockSprite.setPosition(25, 25 + 55 * i);
			Window->draw(BlockSprite);

		}
		BaseSprite.setScale(2.5, 2.5);
		for (int i = 0; i < 3; i++)
		{
			BaseSprite.setTextureRect(sf::IntRect(i * 20, 0, 20, 20));
			BaseSprite.setPosition(25, 300 + i * 55);
			Window->draw(BaseSprite);
		}
		UIText.setPosition(sf::Vector2f(20, 475));
		UIText.setColor(sf::Color(100, 100, 100, 255));
		UIText.setString("Export");
		Window->draw(UISprite);
		Window->draw(UIText);
	}
	void Editor::SelectBlock()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
			if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>25 && mousePos.y < 75)
			{
				SelectedMaterial = '#';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>80 && mousePos.y < 130)
			{
				SelectedMaterial = '1';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>135 && mousePos.y < 185)
			{
				SelectedMaterial = '2';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>190 && mousePos.y < 240)
			{
				SelectedMaterial = '3';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>245 && mousePos.y < 295)
			{
				SelectedMaterial = '0';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>300 && mousePos.y < 350)
			{
				SelectedMaterial = '%';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>355 && mousePos.y < 405)
			{
				SelectedMaterial = '$';
			}
			else if (mousePos.x > 25 && mousePos.x < 75 && mousePos.y>410 && mousePos.y < 460)
			{
				SelectedMaterial = '^';
			}
			else if (mousePos.x > 0 && mousePos.x < 100 && mousePos.y>475 && mousePos.y < 500)
			{
				NameMap();
				Window->close();
			}
		}
	}
	void Editor::EditMatrix()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*Window);
			if (mousePos.x > 120 && mousePos.x < 100 + (Width - 2) * 10 && mousePos.y>20 && mousePos.y < (Height - 2) * 10)
			{
				if (SelectedMaterial == '%')
				{
					if (mousePos.x < 100 + (Width - 3) * 10 && mousePos.y < (Height - 3) * 10 && !BasePlaced)
					{
						int ActualX = mousePos.x - 100;
						int ActualY = mousePos.y;
						a[ActualY / 10][ActualX / 10] = SelectedMaterial;
						a[ActualY / 10 + 1][ActualX / 10] = SelectedMaterial;
						a[ActualY / 10][ActualX / 10 + 1] = SelectedMaterial;
						a[ActualY / 10 + 1][ActualX / 10 + 1] = SelectedMaterial;
						BasePlaced = true;
						BasePosition.X = ActualX / 10;
						BasePosition.Y = ActualY / 10;
					}
				}
				else if (SelectedMaterial == '$')
				{
					if (mousePos.x < 100 + (Width - 3) * 10 && mousePos.y < (Height - 3) * 10 && !PlayerSpawnPlaced)
					{
						int ActualX = mousePos.x - 100;
						int ActualY = mousePos.y;
						a[ActualY / 10][ActualX / 10] = SelectedMaterial;
						a[ActualY / 10 + 1][ActualX / 10] = SelectedMaterial;
						a[ActualY / 10][ActualX / 10 + 1] = SelectedMaterial;
						a[ActualY / 10 + 1][ActualX / 10 + 1] = SelectedMaterial;
						PlayerSpawnPlaced = true;
						PlayerSpawnPosition.X = ActualX / 10;
						PlayerSpawnPosition.Y = ActualY / 10;
					}
				}
				else if (SelectedMaterial == '^')//||SelectedMaterial=='$'||SelectedMaterial=='^')
				{
					if (mousePos.x < 100 + (Width - 3) * 10 && mousePos.y < (Height - 3) * 10 && !OpponentSpawnPlaced)
					{
						int ActualX = mousePos.x - 100;
						int ActualY = mousePos.y;
						a[ActualY / 10][ActualX / 10] = SelectedMaterial;
						a[ActualY / 10 + 1][ActualX / 10] = SelectedMaterial;
						a[ActualY / 10][ActualX / 10 + 1] = SelectedMaterial;
						a[ActualY / 10 + 1][ActualX / 10 + 1] = SelectedMaterial;
						OpponentSpawnPlaced = true;
						OpponentSpawnPosition.X = ActualX / 10;
						OpponentSpawnPosition.Y = ActualY / 10;
					}
				}
				else
				{
					int ActualX = mousePos.x - 100;
					int ActualY = mousePos.y;
					if (a[ActualY / 10][ActualX / 10] == '%')
					{
						BasePlaced = false;
						a[BasePosition.Y][BasePosition.X] = SelectedMaterial;
						a[BasePosition.Y + 1][BasePosition.X] = SelectedMaterial;
						a[BasePosition.Y][BasePosition.X + 1] = SelectedMaterial;
						a[BasePosition.Y + 1][BasePosition.X + 1] = SelectedMaterial;
					}
					else if (a[ActualY / 10][ActualX / 10] == '$')
					{
						PlayerSpawnPlaced = false;
						a[PlayerSpawnPosition.Y][PlayerSpawnPosition.X] = SelectedMaterial;
						a[PlayerSpawnPosition.Y + 1][PlayerSpawnPosition.X] = SelectedMaterial;
						a[PlayerSpawnPosition.Y][PlayerSpawnPosition.X + 1] = SelectedMaterial;
						a[PlayerSpawnPosition.Y + 1][PlayerSpawnPosition.X + 1] = SelectedMaterial;
					}
					else if (a[ActualY / 10][ActualX / 10] == '^')
					{
						OpponentSpawnPlaced = false;
						a[OpponentSpawnPosition.Y][OpponentSpawnPosition.X] = SelectedMaterial;
						a[OpponentSpawnPosition.Y + 1][OpponentSpawnPosition.X] = SelectedMaterial;
						a[OpponentSpawnPosition.Y][OpponentSpawnPosition.X + 1] = SelectedMaterial;
						a[OpponentSpawnPosition.Y + 1][OpponentSpawnPosition.X + 1] = SelectedMaterial;
					}
					else
					{
						a[ActualY / 10][ActualX / 10] = SelectedMaterial;
					}
				}
			}
		}
	}
	void Editor::BuildWalls()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				if (i == 1 || j == 1 || i == Height - 2 || j == Width - 2 || i == 0 || j == 0 || j == Width - 1 || i == Height - 1)
					a[i][j] = '#';
				else
					a[i][j] = '0';
			}
		}
	}

	void Editor::Start()
	{
		LoadTextures();
	    SetDimensions();
		BuildWalls();
		int DesiredHeight;
		if(Height<=50)
        {
            DesiredHeight=500;
        }
        else
        {
            DesiredHeight=10*Height;
        }
        sf::RenderWindow window(sf::VideoMode(100+10*Width, DesiredHeight), "Tanks! Editor!");
        Window = &window;
		while (Window->isOpen())
		{
			sf::Event event;
			while (Window->pollEvent(event))
			{
				SelectBlock();
				EditMatrix();
				if (event.type == sf::Event::Closed)
					Window->close();
			}
			Window->clear();
			DrawBlocks();
			DrawPallete();
			Window->display();
		}
	}
}
