#include "object.h"
#include "renderer.h"
#include "palette.h"
#include <stdlib.h>

namespace object
{
    cuboid::cuboid(position pos, position scale, angular rot, renderer::Camera *renderTarget)
    {
        this->pos = pos;
        this->scale = scale;
        this->rot = rot;
        this->renderTarget = renderTarget;
        // ! Rotation is not yet applied !

        this->points = {
            position{pos.x + (scale.x / 2), pos.y - (scale.y / 2), pos.z - (scale.z / 2)}, // top front right
            position{pos.x - (scale.x / 2), pos.y - (scale.y / 2), pos.z - (scale.z / 2)}, // top front left
            position{pos.x - (scale.x / 2), pos.y + (scale.y / 2), pos.z - (scale.z / 2)}, // bottom front right
            position{pos.x + (scale.x / 2), pos.y + (scale.y / 2), pos.z - (scale.z / 2)}, // bottom front left
            position{pos.x - (scale.x / 2), pos.y - (scale.y / 2), pos.z + (scale.z / 2)}, // top back left
            position{pos.x + (scale.x / 2), pos.y - (scale.y / 2), pos.z + (scale.z / 2)}, // top back right
            position{pos.x - (scale.x / 2), pos.y + (scale.y / 2), pos.z + (scale.z / 2)}, // bottom back right
            position{pos.x + (scale.x / 2), pos.y + (scale.y / 2), pos.z + (scale.z / 2)}  // bottom back left
        };

        this->edges = {
            vertex{0, 1}, vertex{0, 2}, vertex{0, 4},
            vertex{1, 3}, vertex{1, 5},
            vertex{2, 3}, vertex{2, 6},
            vertex{4, 5}, vertex{4, 6},
            vertex{5, 7},
            vertex{6, 7}
        };
    }

    void cuboid::draw_wireframe()
    {
        for (int i = 0; i < 12; ++i){
            vertex v = this->edges[i];
            position2D start = renderer::project(this->points[v.start], *this->renderTarget);
            position2D end = renderer::project(this->points[v.end], *this->renderTarget);
            position2D points[2] = {start, end};
            renderer::render_line(points, *this->renderTarget, White);
        }
    }
} // namespace object
