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
        {-10.0f, -10.0f, 0.0f},  // Top left
        {10.0f, -10.0f, 0.0f},   // Top right
        {10.0f, 10.0f, 0.0f},    // Bottom right
        {-10.0f, 10.0f, 0.0f}    // Bottom left
    };

    while (running)
    {
        EADK::Display::pushRect(EADK::Screen::Full, &Black);

        camera.rotation.pitch += 0.75f;

        renderer::render_quad(squarePoints, camera);

        EADK::Timing::msleep(16);
    }
}
