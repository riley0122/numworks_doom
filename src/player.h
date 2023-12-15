#pragma once
#include "pos.h"

namespace player{
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

    class Velocity{
        public:
            angular direction;
            float strength;
    };
} // namespace player