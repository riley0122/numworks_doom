#ifndef TEST
#include "display.h"
#include "eadkpp.h"
#include "palette.h"
#include "eadk_vars.h"
#include <stdbool.h>
#include "renderer.h"
#include "pos.h"
#include "bsp.h"
#include "player.h"
#include "eadkpp.h"
#include "palette.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include "cube.h"
#include "cone.h"
#include "suzanne.h"

int main(int argc, char *argv[]) {
    bool running = true;

    renderer::Camera camera;
    camera.pos = {0.0f, 0.0f, 0.0f};
    camera.rotation = {0.0f, 0.0f};

    float camspeed = 0.05;

    float rotation = 0;
    float secondaryRotation = 0;

    /*
        0 : cube                                    ; 8   points & 24   edges
        1 : cone                                    ; 33  points & 128  edges
        2 : suzanne (blender default monkey model)  ; 507 points & 1968 edges
    */
    int model = 0;

    while (running)
    {
        // exit condition
        EADK::Keyboard::State kbd = EADK::Keyboard::scan();
        running = !kbd.keyDown(EADK::Keyboard::Key::Backspace);

        EADK::Display::pushRectUniform(EADK::Screen::Full, Black);

        EADK::Display::drawString("Prototype", EADK::Point(0,0), true, White, Black);

        if (kbd.keyDown(EADK::Keyboard::Key::Up))
        {
            rotation += 0.1;
        } else if (kbd.keyDown(EADK::Keyboard::Key::Down))
        {
            rotation -= 0.1;
        }

        if (kbd.keyDown(EADK::Keyboard::Key::Left))
        {
            secondaryRotation += 0.1;
        } else if (kbd.keyDown(EADK::Keyboard::Key::Right)){
            secondaryRotation -= 0.1;
        }

        if (kbd.keyDown(EADK::Keyboard::Key::One))
        {
            model = 0;
            rotation = 0;
            secondaryRotation = 0;
        } else if (kbd.keyDown(EADK::Keyboard::Key::Two))
        {
            model = 1;
            rotation = 0;
            secondaryRotation = 0;
        } else if (kbd.keyDown(EADK::Keyboard::Key::Three))
        {
            model = 2;
            rotation = 0;
            secondaryRotation = 0;
        }

        // position2D topLeft = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(Cube::points[0], secondaryRotation), rotation), camera);
        // EADK::Display::drawString("0", EADK::Point(topLeft.x, topLeft.y), false, White, Black);

        switch (model)
        {
        case 0:
            for (vertex v : Cube::edges){
                position startPoint = Cube::points[v.start];
                position endPoint = Cube::points[v.end];
                position2D start = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(startPoint, secondaryRotation), rotation), camera);
                position2D end = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(endPoint, secondaryRotation), rotation), camera);
                position2D points[2] = {start, end};
                renderer::render_line(points, camera, White);
            }
            break;
        case 1:
            for (vertex v : Cone::edges){
                position startPoint = Cone::points[v.start];
                position endPoint = Cone::points[v.end];
                position2D start = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(startPoint, secondaryRotation), rotation), camera);
                position2D end = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(endPoint, secondaryRotation), rotation), camera);
                position2D points[2] = {start, end};
                renderer::render_line(points, camera, White);
            }
            break;
        case 2:
            for (vertex v : Suzanne::edges){
                position startPoint = Suzanne::points[v.start];
                position endPoint = Suzanne::points[v.end];
                position2D start = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(startPoint, secondaryRotation), rotation), camera);
                position2D end = renderer::project(renderingMaths::rotateX(renderingMaths::rotateY(endPoint, secondaryRotation), rotation), camera);
                position2D points[2] = {start, end};
                renderer::render_line(points, camera, White);
            }
        break;
        default:
            break;
        }



        // rotation += 3;
        EADK::Timing::msleep(33.3);
    }
}

#else
#include "utest.h"
#include <exception>
#include <cmath>
#include <iostream>
#include "renderer.h"

// Rounds numbers to 3 decimal points
float r(float number)
{
    int value = std::round(number * 1000);
    return (float)value / 1000;
}

UTEST(renderingMaths, globalRelativeConversion)
{
    renderer::Camera camera;
    camera.pos = {0,0,0};
    camera.rotation = {0,0};

    position point = { 1, 2, 3 };
    renderingMaths::globalToRelative(&point, camera);

    ASSERT_EQ(point.x, 1);
    ASSERT_EQ(point.y, 2);
    ASSERT_EQ(point.z, 3);

    // Not yet Implemented.
    camera.rotation.yaw += 10;
    camera.rotation.pitch += 10;
    // ASSERT_NE(point.x, 1);
    // ASSERT_NE(point.y, 2);
    // ASSERT_NE(point.x, 3);
}

UTEST(renderingMaths, rotation) 
{
    position point = {1, 2, 3};

    // Validation data calculated with
    // https://www.mathforengineers.com/math-calculators/3D-point-rotation-calculator.html

    // 20 in radians == 1145.92 in degrees

    position pointRotated = renderingMaths::rotateX(point, 20);
    ASSERT_EQ(r(pointRotated.x), r(point.x));
    ASSERT_EQ(r(pointRotated.y), -1.923f);
    ASSERT_EQ(r(pointRotated.z), 3.050f);

    pointRotated = renderingMaths::rotateY(point, 20);
    ASSERT_EQ(r(pointRotated.x), 3.147f);
    ASSERT_EQ(r(pointRotated.y), r(point.y));
    ASSERT_EQ(r(pointRotated.z), 0.311f);

    pointRotated = renderingMaths::rotateZ(point, 20);
    ASSERT_EQ(r(pointRotated.x), -1.418f);
    ASSERT_EQ(r(pointRotated.y), 1.729f);
    ASSERT_EQ(r(pointRotated.z), r(point.z));
}

UTEST_MAIN();
#endif
