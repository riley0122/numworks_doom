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

    while (running)
    {
        // exit condition
        EADK::Keyboard::State kbd = EADK::Keyboard::scan();
        running = !kbd.keyDown(EADK::Keyboard::Key::Backspace);

        EADK::Display::pushRectUniform(EADK::Screen::Full, Black);

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

        for (int i = 0; i < 12; ++i){
            vertex v = edges[i];
            position2D start = renderer::project(points[v.start], camera);
            position2D end = renderer::project(points[v.end], camera);
            position2D points[2] = {start, end};
            EADK::Display::pushRectUniform(EADK::Rect(start.x -1 , start.y - 1, 3, 3), Blue);
            EADK::Display::pushRectUniform(EADK::Rect(end.x -1 , end.y - 1, 3, 3), Purple);
            EADK::Timing::msleep(1000);
            renderer::render_line(points, camera, White);
            EADK::Timing::msleep(1000);
        }

        EADK::Timing::msleep(16);
    }
}
