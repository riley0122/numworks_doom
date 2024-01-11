#pragma once

#include "pos.h"
#include "renderer.h"
#include <vector>

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
        void draw_wireframe();
        void setX(float ammount);
        void setY(float ammount);
        void setZ(float ammount);
        void setDepth(float ammount);
        void setWidth(float ammount);
        void setHeight(float ammount);
        std::vector<position> points;
        std::vector<vertex> edges;
    };

} // namespace object
