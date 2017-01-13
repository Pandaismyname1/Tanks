#include "Map.h"
namespace Game
{
	Map::Map()
	{

	}

	void Map::Load(char FileName[])
	{
		std::ifstream File;
		char str[80];
		strcpy(str,"Resources/Maps/");
		strcat(str,FileName);
		File.open(str);
		File >> Width >> Height;
		for ( int i = 0 ; i < 100 ; i++ )
            Matrix[i].resize(100);
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				File >> Matrix[i][j];
			}
		}
	}

	Map::~Map()
	{
		//dtor
	}

}
