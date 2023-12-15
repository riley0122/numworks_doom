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

    while (running)
    {
        EADK::Keyboard::State kbdState = EADK::Keyboard::scan();

    }
}
