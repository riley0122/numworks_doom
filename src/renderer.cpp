#include "renderer.h"
#include "pos.h"
#include "eadkpp.h"
#include "palette.h"
#include <cmath>

namespace renderer
{
    void render_quad(position points[4], Camera target){
        position transformedPoints[4];
        for (int i = 0; i < 4; ++i)
        {
            // Rotate the points based on the camera's yaw
            float dx = points[i].x - target.pos.x;
            float dy = points[i].y - target.pos.y;

            // Rotate the point around the camera position
            transformedPoints[i].x = target.pos.x + dx * cos(target.rotation.yaw) - dy * sin(target.rotation.yaw);
            transformedPoints[i].y = target.pos.y + dx * sin(target.rotation.yaw) + dy * cos(target.rotation.yaw);
            transformedPoints[i].z = points[i].z;
        }

        EADK::Rect rect = {
            static_cast<uint16_t>(transformedPoints[0].x),
            static_cast<uint16_t>(transformedPoints[0].y),
            static_cast<uint16_t>(transformedPoints[2].x - transformedPoints[0].x),
            static_cast<uint16_t>(transformedPoints[2].y - transformedPoints[0].y)};

        EADK::Display::pushRect(rect, &Purple);
    }
} // namespace renderer
