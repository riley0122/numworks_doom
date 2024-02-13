/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
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
    void globalToRelative(position *point, renderer::Camera target);
    position rotateX(position point, float angle);
    position rotateY(position point, float angle);
    position rotateZ(position point, float angle);
    int countIntersections(position2D point, std::vector<vertex> edges, std::vector<position> points, renderer::Camera camera);
} // namespace renderingMaths
