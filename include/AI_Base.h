#include "Tank.h"
#include <list>
namespace Game
{
#ifndef AI_BASE_H
#define AI_BASE_H


class AI_Base
{
    public:
        AI_Base();
        virtual ~AI_Base();
        Tank *AITank;
        bool alive=true;
        int SpawnX,SpawnY;
        int tick=0;
        virtual void Tick();
        void Respawn();

    protected:

    private:
};

#endif // AI_BASE_H
}
