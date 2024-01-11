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
#include "object.h"
#include <stdlib.h>

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
        running = !kbd.keyDown(EADK::Keyboard::Key::Power);

        EADK::Display::pushRectUniform(EADK::Screen::Full, Black);

        object::cuboid cube = object::cuboid({0, 0, 0}, {30, 30, 30}, {0, 0}, &camera);
        // cube.draw_wireframe();

        EADK::Timing::msleep(16);
    }
}
