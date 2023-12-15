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
            float pitch;
            float yaw;
            float strenght;
    };
} // namespace player