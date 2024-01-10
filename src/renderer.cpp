#include "renderer.h"
#include "pos.h"
#include "eadkpp.h"
#include "palette.h"

#define FOCAL_LENGTH 30

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

    float pow(int base, int exp)
    {
        float result = 1.0f;
        for (int i = 0; i < exp; i++)
        {
            result *= base;
        }
        return result;
    }

    // sin and cos are based on taylor series
    float sin(float angle)
    {
        float result = 0.0f;
        for (int i = 0; i < 10; i++)
        {
            result += (pow(-1, i) / factorial(2 * i + 1)) * pow(angle, 2 * i + 1);
        }
        return result;
    }

    float cos(float angle)
    {
        return sin(90 - angle);
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

        // TODO: Modify points based on position and rotation

        *point = p;
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

    position2D *render_quad(position points[4], Camera target, EADK::Color colour)
    {
        static position2D screenPoints[4];
        for (int i = 0; i < 4; i++)
        {
            screenPoints[i] = project(points[i], target);
        }

        for (int i = 0; i < 4; i++)
        {
            if (screenPoints[i].x < 0 || screenPoints[i].x > EADK::Screen::Width || screenPoints[i].y < 0 || screenPoints[i].y > EADK::Screen::Height)
                continue;
            EADK::Rect point(
                screenPoints[i].x - 1,
                screenPoints[i].y - 1,
                3, 3);
            EADK::Display::pushRectUniform(point, colour);
        }

        return screenPoints;
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
