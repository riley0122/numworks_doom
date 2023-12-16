#pragma once
#include"pos.h"

namespace renderer{
    class Camera{
    public:
        position pos;
        angular rotation;
    };
    void render_quad(position points[4], Camera target);
} // namespace renderer