#include "renderer.h"
#include "pos.h"
#include "eadkpp.h"
#include "palette.h"

namespace renderingMaths{
    float factorial(int n) {
        if(n == 0 || n == 1){
            return 1.0f;
        }else{
            return n * factorial(n - 1);
        }
    }

    float pow(int base, int exp){
        float result = 1.0f;
        for (int i = 0; i < exp; i++)
        {
            result *= base;
        }
        return result;
    }

    // sin and cos are based on taylor series
    float sin(float angle){
        float result = 0.0f;
        for (int i = 0; i < 10; i++)
        {
            result += (pow(-1, i) / factorial(2*i+1)) * pow(angle, 2 * i + 1);
        }
        return result;
    }

    float cos(float angle){
        return sin(90 - angle);
    }

} // renderingMaths

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
            transformedPoints[i].x = target.pos.x + dx * renderingMaths::cos(target.rotation.yaw) - dy * renderingMaths::sin(target.rotation.yaw);
            transformedPoints[i].y = target.pos.y + dx * renderingMaths::sin(target.rotation.yaw) + dy * renderingMaths::cos(target.rotation.yaw);
            transformedPoints[i].z = points[i].z;
        }

        EADK::Rect rect(
            static_cast<uint16_t>(transformedPoints[0].x),
            static_cast<uint16_t>(transformedPoints[0].y),
            static_cast<uint16_t>(transformedPoints[2].x - transformedPoints[0].x),
            static_cast<uint16_t>(transformedPoints[2].y - transformedPoints[0].y)
        );

        EADK::Display::pushRect(rect, &Purple);
    }
} // namespace renderer
