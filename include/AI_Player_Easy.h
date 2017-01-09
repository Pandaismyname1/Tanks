#include "Tank.h"
#include "AI_Base.h"
namespace Game
{

    #ifndef AI_PLAYER_EASY_H
    #define AI_PLAYER_EASY_H

    class AI_Player_Easy : public AI_Base
    {
        public:
            Tank *AITank;
            bool alive=true;
            int SpawnX,SpawnY;
            int tick=0;
            AI_Player_Easy();
            virtual ~AI_Player_Easy();
            virtual void Tick();
            void Respawn();

        protected:

        private:
    };

    #endif // AI_PLAYER_EASY_H
}
