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
    position2D project(position point, Camera target);
    void render_line(position2D points[2], Camera target, EADK::Color colour); // Renders a single 2D line
} // namespace renderer

namespace renderingMaths
{
    float factorial(int n);
    float pow(int base, int exp);
    float sin(int angle);
    float cos(int angle);
    float sqrt(float number);
    int floor(float number);
    float abs(float number);
    void globalToRelative(position *point, renderer::Camera target);
    position rotateX(position point, float angle);
    void rotateY(position *point, float angle);
    void rotateZ(position *point, float angle);
} // namespace renderingMaths
