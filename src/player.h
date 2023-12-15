#pragma once

namespace player{
    class player{
    public:
        float x;
        float y;
        float z;
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