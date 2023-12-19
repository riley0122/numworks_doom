#include "renderer.h"
#include "pos.h"
#include "eadkpp.h"
#include "palette.h"

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
} // renderingMaths

namespace renderer
{
    void render_quad(position points[4], Camera target)
    {
        position2D screenPoints[4];
        for (int i = 0; i < 4; i++)
        {
            screenPoints[i].x = points[i].x / (points[i].z + 1 + target.pos.z) - target.pos.x;
            screenPoints[i].y = points[i].y / (points[i].z + 1 + target.pos.z) + target.pos.y;
        }

        for (int i = 0; i < 4; i++)
        {
            EADK::Rect point(
                screenPoints[i].x,
                screenPoints[i].y,
                5, 5);
            EADK::Display::pushRectUniform(point, White);
        }
    }

    void render_line(position2D points[2], Camera target, EADK::Color colour)
    {
        int Dx = points[0].x > points[1].x ? points[0].x - points[1].x : points[1].x - points[0].x;
        int Dy = points[0].y > points[1].y ? points[0].y - points[1].y : points[1].y - points[0].y;

        float length = renderingMaths::sqrt(renderingMaths::pow(Dx, 2) + renderingMaths::pow(Dy, 2));
        int steps = renderingMaths::floor(length / 5);

        float unitWidth = Dx / steps;
        float unitHeight = Dy / steps;

        int horizontalStepSize = renderingMaths::floor(Dx / steps);
        int verticalStepSize = renderingMaths::floor(Dy / steps);

        for (int i = 0; i < steps; i++)
        {
            EADK::Display::pushRectUniform(EADK::Rect(points[0].x > points[1].x ? points[0].x : points[1].x + i * horizontalStepSize, points[0].y > points[1].y ? points[0].y : points[1].y + i * verticalStepSize, unitWidth, unitHeight), colour);
        }
    }
} // namespace renderer
