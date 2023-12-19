#pragma once

#include "pos.h"
#include "renderer.h"

namespace object
{
    class cuboid
    {
    private:
        position pos;
        angular rot;
        position scale;
        renderer::Camera *renderTarget;

    public:
        cuboid(position pos, position scale, angular rot, renderer::Camera *renderTarget);
        position2D **draw_points();
        void draw_wireframe(position2D **projectionResult);
        void setX(float ammount);
        void setY(float ammount);
        void setZ(float ammount);
        void setDepth(float ammount);
        void setWidth(float ammount);
        void setHeight(float ammount);
    };

} // namespace object
