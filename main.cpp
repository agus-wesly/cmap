#include <stdio.h>
#include "third_party/raylib/raylib.h"
#include "plug.h"

#define CR_HOST
#include "third_party/cr/cr.h"

Plug plug{};

int main() {
    cr_plugin ctx;
    cr_plugin_open(ctx, "./plug.so");
    ctx.userdata = (void *) &plug;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "C Map");
    SetTargetFPS(60);

    while (!plug.exit_window)
    {
        cr_plugin_update(ctx);
    }

    CloseWindow();
    return 0;
}
