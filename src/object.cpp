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
        this->rot = {0, 0};
        // Rotation is not yet applied
        this->renderTarget = renderTarget;
    }

    position2D **cuboid::draw_points()
    {
        float x = this->pos.x;
        float y = this->pos.y;
        float z = this->pos.z;
        float width = this->scale.x;
        float Height = this->scale.y;
        float depth = this->scale.z;

        position frontSquare[4] = {
            {x - (width / 2), y - (Height / 2), z + (depth / 2)}, // top left
            {x + (width / 2), y - (Height / 2), z + (depth / 2)}, // top right
            {x - (width / 2), y + (Height / 2), z + (depth / 2)}, // bottom right
            {x + (width / 2), y + (Height / 2), z + (depth / 2)}  // bottom left
        };

        position backSquare[4] = {
            {x - (width / 2), y - (Height / 2), z - (depth / 2)}, // top left
            {x + (width / 2), y - (Height / 2), z - (depth / 2)}, // top right
            {x - (width / 2), y + (Height / 2), z - (depth / 2)}, // bottom right
            {x + (width / 2), y + (Height / 2), z - (depth / 2)}  // bottom left
        };

        position2D *backProjection = renderer::render_quad(backSquare, *this->renderTarget);
        position2D *frontProjection = renderer::render_quad(frontSquare, *this->renderTarget);

        position2D **bothProjections;
        bothProjections = (position2D **)malloc(3 * sizeof(position2D *));
        bothProjections[0] = backProjection;
        bothProjections[1] = frontProjection;

        return bothProjections;
    }

    void cuboid::draw_wireframe(position2D **projectionResult)
    {
        position2D *backProjection = projectionResult[0];
        position2D *frontProjection = projectionResult[1];

        for (int i = 1; i < 4; i++)
        {
            position2D selected[] = {backProjection[i], backProjection[i - 1]};
            renderer::render_line(selected, *this->renderTarget, White);
        }

        for (int i = 1; i < 4; i++)
        {
            position2D selected[] = {frontProjection[i], frontProjection[i - 1]};
            renderer::render_line(selected, *this->renderTarget, White);
        }

        for (int i = 1; i < 4; i++)
        {
            position2D selected[] = {frontProjection[i], backProjection[i]};
            renderer::render_line(selected, *this->renderTarget, White);
        }
    }
} // namespace object
