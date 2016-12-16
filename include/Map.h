#include <fstream>
namespace Game
{
    #ifndef MAP_H
    #define MAP_H

    class Map
    {
        public:
            Map();
            void Load(char[]);
            int Width;
            int Height;
            char Matrix[100][100];
            virtual ~Map();

        protected:

        private:
    };

    #endif // MAP_H
}
