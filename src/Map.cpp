#include "Map.h"
namespace Game
{
    Map::Map()
    {

    }

    void Map::Load(char FileName[])
    {
        std::ifstream File;
        File.open(FileName);
        File>>Width>>Height;
        for(int i=0;i<Width;i++)
        {
            for(int j=0;j<Height;j++)
            {
                File>>Matrix[i][j];
            }
        }
    }

    Map::~Map()
    {
        //dtor
    }

}
