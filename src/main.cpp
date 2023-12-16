#include "display.h"
#include "eadkpp.h"
#include "palette.h"
#include "eadk_vars.h"
#include <stdbool.h>
#include "renderer.h"
#include "pos.h"
#include "bsp.h"
#include "player.h"

int main(int argc, char *argv[])
{
    EADK::Display::pushRectUniform(EADK::Screen::Rect, Purple);

    bool running = true;

    renderer::Camera cam = renderer::Camera();
    position camPos;
    camPos.x = 0;
    camPos.y = 0;
    camPos.z = 0;
    cam.pos = camPos;
    angular camRot;
    camRot.pitch = 0;
    camRot.yaw = 0;
    cam.rotation = camRot;

    while (running)
    {
        /* Nothing to do yet */
    }
}
