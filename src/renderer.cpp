#include "renderer.h"
#include "pos.h"
#include "eadkpp.h"
#include "palette.h"
#include <stdlib.h>

#include <cmath>

#define FOCAL_LENGTH 30
#define PI 3.141592653589793238462643383279502884197
#define TERMS 10

namespace renderingMaths
{
    // convert from global coordinates to relative coordinates
    void globalToRelative(position *point, renderer::Camera target){
        position p = *point;

        // TODO: Modify points based on camera position and rotation

        *point = p;
    }

    position rotateX(position point, float angle){
        position p;
        p.y = (point.y * std::cos(angle)) - (std::sin(angle) * point.z);
        p.z = (point.y * std::sin(angle)) + (std::cos(angle) * point.z);
        p.x = point.x;
        return p;
    }

} // renderingMaths

namespace renderer
{
    // Project a single point
    position2D project(position point, Camera target){
        renderingMaths::globalToRelative(&point, target);
        float projectedX = (point.x * FOCAL_LENGTH) / (point.z + FOCAL_LENGTH);
        float projectedY = (point.y * FOCAL_LENGTH) / (point.z + FOCAL_LENGTH);

        // Move to center of screen
        projectedX += EADK::Screen::Width / 2;
        projectedY += EADK::Screen::Height / 2;

        return {projectedX, projectedY};
    }

    void render_line(position2D points[2], Camera target, EADK::Color colour)
    {
        float Dx = points[1].x - points[0].x;
        float Dy = points[1].y - points[0].y;

        if (points[0].x < points[1].x)
        {
            float y;
            for (int x = std::floor(points[0].x); x < std::floor(points[1].x); x++)
            {
                y = points[0].y + Dy * (x - points[0].x) / Dx;
                EADK::Display::pushRectUniform(EADK::Rect(x, y, 1, 1), colour);
            }
        }else if(Dx == 0){
            EADK::Display::pushRectUniform(EADK::Rect(points[0].x, points[0].y < points[1].y ? points[0].y : points[1].y, 1, std::abs(Dy)), colour);
        }else {
            float y;
            for(int x = std::floor(points[1].x); x < std::floor(points[0].x); x++)
            {
                y = points[1].y + Dy * (x - points[1].x) / Dx;
                EADK::Display::pushRectUniform(EADK::Rect(x, y, 1, 1), colour);
            }
        }
    }
} // namespace renderer
