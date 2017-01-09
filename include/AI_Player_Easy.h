#include "Tank.h"
namespace Game
{

    #ifndef AI_PLAYER_EASY_H
    #define AI_PLAYER_EASY_H

    class AI_Player_Easy
    {
        public:
            Tank *AITank;
            bool alive=true;
            int SpawnX,SpawnY;
            std::list<Game::AI_Player_Easy> *AIList;
            int tick=0;
            AI_Player_Easy();
            virtual ~AI_Player_Easy();
            void Tick();
            void Respawn();

        protected:

        private:
    };

    #endif // AI_PLAYER_EASY_H
}
