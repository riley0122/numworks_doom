#pragma once
#include"pos.h"

namespace renderer{
    class Camera{
    public:
        position pos;
    };
    void render_quad(position points[4]);
}