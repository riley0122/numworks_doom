#pragma once
#include "pos.h"

namespace player{
    typedef struct Velocity{
        angular direction;
        float strength;
    } Velocity;

    class player{
    public:
        position pos;
        void applyVelocity(Velocity velo);
        Velocity getVelocity();
    private:
        float Vx;
        float Vy;
        float Vz;
    };
} // namespace player