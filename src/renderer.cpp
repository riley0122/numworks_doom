#include "renderer.h"
#include "pos.h"
#include "eadkpp.h"
#include "palette.h"
#include <stdlib.h>

#define FOCAL_LENGTH 30
#define PI 3.141592653589793238462643383279502884197
#define TERMS 10

namespace renderingMaths
{
    float factorial(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1.0f;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }

    float pow(int base, int exp) {
        if(exp < 0) {
            if(base == 0)
                return -0;
            return 1 / (base * pow(base, (-exp) - 1));
        }
        if(exp == 0)
            return 1;
        if(exp == 1)
            return base;
        return base * pow(base, exp - 1);
    }

    // sin and cos are based on taylor series
    float sin(int deg) {
        deg %= 360; // make it less than 360
        float rad = deg * PI / 180;
        float sin = 0;

        int i;
        for(i = 0; i < TERMS; i++) {
            sin += pow(-1, i) * pow(rad, 2 * i + 1) / factorial(2 * i + 1);
        }
        return sin;
    }

    float cos(int deg) {
        deg %= 360; // make it less than 360
        float rad = deg * PI / 180;
        float cos = 0;

        int i;
        for(i = 0; i < TERMS; i++) {
            cos += pow(-1, i) * pow(rad, 2 * i) / factorial(2 * i);
        }
        return cos;
    }

    float sqrt(float number)
    {
        float error = number * 10e-3;
        float s = number;

        while ((s - number / s) > error)
        {
            s = (s + number / s) / 2;
        }
        return s;
    }

    int floor(float number)
    {
        if (number >= 0.0)
        {
            return int(number);
        }
        else
        {
            return (int(number) - 1);
        }
    }

    float abs(float number)
    {
        return number >= 0 ? number : -1 * number;
    }

    // conversion functions

    // convert from global coordinates to relative coordinates
    void globalToRelative(position *point, renderer::Camera target){
        position p = *point;

        // TODO: Modify points based on camera position and rotation

        *point = p;
    }

    position rotateX(position point, float angle){
        position p;
        p.y = (point.y * cos(angle)) - (sin(angle) * point.z);
        p.z = (point.y * sin(angle)) + (cos(angle) * point.z);
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
            for (int x = renderingMaths::floor(points[0].x); x < renderingMaths::floor(points[1].x); x++)
            {
                y = points[0].y + Dy * (x - points[0].x) / Dx;
                EADK::Display::pushRectUniform(EADK::Rect(x, y, 1, 1), colour);
            }
        }else if(Dx == 0){
            EADK::Display::pushRectUniform(EADK::Rect(points[0].x, points[0].y < points[1].y ? points[0].y : points[1].y, 1, renderingMaths::abs(Dy)), colour);
        }else {
            float y;
            for(int x = renderingMaths::floor(points[1].x); x < renderingMaths::floor(points[0].x); x++)
            {
                y = points[1].y + Dy * (x - points[1].x) / Dx;
                EADK::Display::pushRectUniform(EADK::Rect(x, y, 1, 1), colour);
            }
        }
    }
} // namespace renderer
