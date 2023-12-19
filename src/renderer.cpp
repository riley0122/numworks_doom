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

    float abs(float number)
    {
        return number >= 0 ? number : -1 * number;
    }
} // renderingMaths

namespace renderer
{
    position2D *render_quad(position points[4], Camera target)
    {
        static position2D screenPoints[4];
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

        return screenPoints;
    }

    void render_line(position2D points[2], Camera target, EADK::Color colour)
    {
        float Dx = renderingMaths::abs(points[1].x - points[0].x);
        float Sx = points[0].x < points[1].x ? 1 : -1;

        float Dy = -1 * renderingMaths::abs(points[1].y - points[1].y);
        float Sy = points[0].y < points[1].y ? 1 : -1;

        float error = Dx + Dy;

        position2D currentPos[2] = {{points[0].x, points[0].y}, {points[1].x, points[1].y}};
        while (true)
        {
            EADK::Display::pushRectUniform(EADK::Rect(currentPos[0].x, currentPos[0].y, 2, 2), colour);
            if (currentPos[0].x == currentPos[1].x && currentPos[1].x == currentPos[1].y)
                break;

            float e2 = 2 * error;
            if (e2 >= Dy)
            {
                if (currentPos[0].x == currentPos[1].x)
                    break;
                error += Dy;
                currentPos[0].x += Sx;
            }

            if (e2 <= Dx)
            {
                if (currentPos[0].y == currentPos[1].y)
                    break;
                error += Dx;
                currentPos[0].y += Sy;
            }
        }
    }
} // namespace renderer
