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

int main(int argc, char *argv[])
{
    bool running = true;

    renderer::Camera camera;
    camera.pos = {0.0f, 0.0f, 0.0f};
    camera.rotation = {0.0f, 0.0f};

    float camspeed = 0.05;

    float rotation = 0;

    while (running)
    {
        // exit condition
        EADK::Keyboard::State kbd = EADK::Keyboard::scan();
        running = !kbd.keyDown(EADK::Keyboard::Key::Backspace);

        EADK::Display::pushRectUniform(EADK::Screen::Full, Black);

        EADK::Display::drawString("Prototype", EADK::Point(0,0), true, White, Black);

        if(kbd.keyDown(EADK::Keyboard::Key::Up)){
            rotation += 10;
        }else if(kbd.keyDown(EADK::Keyboard::Key::Down)){
            rotation -= 10;
        }

        // object::cuboid cube = object::cuboid({0, 0, 0}, {30, 30, 30}, {0, 0}, &camera);
        // cube.draw_wireframe();

        position points[8] = {
            position{-15, 15, 15}, // top front left
            position{15, 15, 15}, // top front right
            position{-15, -15, 15}, // bottom front left
            position{15, -15, 15}, // bottom front right
            position{-15, 15, -15}, // top back left
            position{15, 15, -15}, // top back right
            position{-15, -15, -15}, // bottom back left
            position{15, -15, -15}  // bottom back right
        };

        vertex edges[12] = {
            vertex{0,1},
            vertex{0,4},
            vertex{0,2},
            vertex{1,3},
            vertex{1,5},
            vertex{2,6},
            vertex{3,7},
            vertex{2,3},
            vertex{4,5},
            vertex{4,6},
            vertex{5,7},
            vertex{6,7}
        };

        position2D topLeft = renderer::project(points[0], camera);
        EADK::Display::drawString("0", EADK::Point(topLeft.x, topLeft.y), false, White, Black);

        for (int i = 0; i < 12; ++i){
            vertex v = edges[i];
            position startPoint = points[v.start];
            position endPoint = points[v.end];
            position2D start = renderer::project(renderingMaths::rotateX(startPoint, rotation), camera);
            position2D end = renderer::project(renderingMaths::rotateX(endPoint, rotation), camera);
            position2D points[2] = {start, end};
            renderer::render_line(points, camera, White);
        }

        // rotation += 3;
        EADK::Timing::msleep(33.3);
    }
}
