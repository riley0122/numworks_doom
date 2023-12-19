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
        
    }
} // namespace renderer
