#pragma once
#include "pos.h"
#include "eadkpp.h"

namespace renderer
{
    class Camera
    {
    public:
        position pos;
        angular rotation;
    };
    position2D *render_quad(position points[4], Camera target, EADK::Color colour);
    void render_line(position2D points[2], Camera target, EADK::Color colour); // Renders a single 2D line
} // namespace renderer