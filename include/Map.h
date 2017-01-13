#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
namespace Game
{
    #ifndef MAP_H
    #define MAP_H

    class Map
    {
        public:
            Map();
            void Load(char FileName[]);
            int Width;
            int Height;
            std::vector<std::vector<char> > Matrix = std::vector<std::vector<char> >(100);
            virtual ~Map();

        protected:

        private:
    };

    #endif // MAP_H
}
