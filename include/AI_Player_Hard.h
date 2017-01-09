#include <Tank.h>
#include <AI_Base.h>
namespace Game
{

#ifndef AI_PLAYER_HARD_H
#define AI_PLAYER_HARD_H


class AI_Player_Hard : public AI_Base
{
    public:
        AI_Player_Hard();
        virtual ~AI_Player_Hard();

        Tank *AITank;
        bool alive=true;
        int SpawnX,SpawnY;
        int tick=0;
        virtual void Tick();
        void Respawn();
    protected:

    private:
};

#endif // AI_PLAYER_HARD_H
}
