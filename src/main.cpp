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

int main(int argc, char *argv[])
{
    bool running = true;

    renderer::Camera camera;
    camera.pos = {0.0f, 0.0f, 0.0f};
    camera.rotation = {0.0f, 0.0f};

    position squarePoints[4] = {
        {50.0f, 50.0f, 0.0f},  // Top left
        {80.0f, 50.0f, 0.0f},   // Top right
        {80.0f, 80.0f, 0.0f},    // Bottom right
        {50.0f, 80.0f, 0.0f}    // Bottom left
    };

    while (running)
    {
        // exit condition
        EADK::Keyboard::State kbd = EADK::Keyboard::scan();
        running = !(kbd.keyDown(EADK::Keyboard::Key::Home) && kbd.keyDown(EADK::Keyboard::Key::Back));

        // Basic camera controlls
        if(kbd.keyDown(EADK::Keyboard::Key::Left)){
            camera.pos.x -= 3;
        }
        if(kbd.keyDown(EADK::Keyboard::Key::Right)){
            camera.pos.x += 3;
        }
        if(kbd.keyDown(EADK::Keyboard::Key::Down)){
            camera.pos.y -= 3;
        }
        if(kbd.keyDown(EADK::Keyboard::Key::Up)){
            camera.pos.y += 3;
        }

        EADK::Display::pushRectUniform(EADK::Screen::Full, Black);

        renderer::render_quad(squarePoints, camera);

        EADK::Timing::msleep(16);
    }
}
