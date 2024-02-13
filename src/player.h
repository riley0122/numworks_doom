/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
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