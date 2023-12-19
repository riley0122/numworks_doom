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

int main(int argc, char *argv[])
{
    bool running = true;

    renderer::Camera camera;
    camera.pos = {0.0f, 0.0f, 0.0f};
    camera.rotation = {0.0f, 0.0f};

    position squarePoints[4] = {
        {50.0f, 50.0f, 0.0f}, // Top left
        {80.0f, 50.0f, 0.0f}, // Top right
        {80.0f, 80.0f, 0.0f}, // Bottom right
        {50.0f, 80.0f, 0.0f}  // Bottom left
    };

    position secondSquarePoints[4] = {
        {50.0f, 50.0f, -1.1f}, // Top left
        {80.0f, 50.0f, -1.1f}, // Top right
        {80.0f, 80.0f, -1.1f}, // Bottom right
        {50.0f, 80.0f, -1.1f}  // Bottom left
    };

    while (running)
    {
        // exit condition
        EADK::Keyboard::State kbd = EADK::Keyboard::scan();
        running = !(kbd.keyDown(EADK::Keyboard::Key::Home) && kbd.keyDown(EADK::Keyboard::Key::Back));

        // Basic camera controlls
        if (kbd.keyDown(EADK::Keyboard::Key::Left))
        {
            camera.pos.x -= 3;
        }
        if (kbd.keyDown(EADK::Keyboard::Key::Right))
        {
            camera.pos.x += 3;
        }
        if (kbd.keyDown(EADK::Keyboard::Key::Down))
        {
            camera.pos.y -= 3;
        }
        if (kbd.keyDown(EADK::Keyboard::Key::Up))
        {
            camera.pos.y += 3;
        }
        if (kbd.keyDown(EADK::Keyboard::Key::Minus))
        {
            camera.pos.z -= 0.05;
        }
        if (kbd.keyDown(EADK::Keyboard::Key::Plus))
        {
            camera.pos.z += 0.05;
        }

        EADK::Display::pushRectUniform(EADK::Screen::Full, Black);

        position2D *firstScreenPoints = renderer::render_quad(squarePoints, camera);
        position2D *secondScreenPoints = renderer::render_quad(secondSquarePoints, camera);

        position2D points[] = {{100, 100}, {200, 200}};
        renderer::render_line(points, camera, Purple);

        EADK::Timing::msleep(16);
    }
}
