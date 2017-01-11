#include <iostream>
#include <fstream>
#include <cstring>
#include <SFML/Graphics.hpp>
#include <sstream>
namespace Game
{
#ifndef EDITOR_H
#define EDITOR_H

	struct Position
	{
		int X, Y;
	};



	class Editor
	{
	public:
		Editor();
		virtual ~Editor();
		char a[100][100];
		char SelectedMaterial = '0';
		int Width = 50, Height = 50;
		bool BasePlaced = false;
		bool PlayerSpawnPlaced = false;
		bool OpponentSpawnPlaced = false;
		Position BasePosition;
		Position PlayerSpawnPosition;
		Position OpponentSpawnPosition;
		sf::Texture MaterialTexture;
		sf::Sprite BlockSprite;
		sf::RenderWindow *Window;
		sf::Texture BaseTexture;
		sf::Sprite BaseSprite;
		sf::Texture UITexture;
		sf::Sprite UISprite;
		sf::Text UIText;
		sf::Font UIFont;
		std::string FileName;
		void Start();
		void BuildWalls();
		void EditMatrix();
		void SelectBlock();
		void DrawPallete();
		void DrawBlocks();
		void LoadTextures();
		void NameMap();
		void SetDimensions();
		void ExportMap(std::string NewFileName);

	protected:

	private:
	};

#endif // EDITOR_H
}
