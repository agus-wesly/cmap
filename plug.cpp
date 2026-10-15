#include "plug.h"
#include "./third_party/raylib/raylib.h"
#include "./third_party/cr/cr.h"
#include <cstddef>
#include <sqlite3.h>

Plug *plug = nullptr;

size_t image_idx = 0;
Texture2D images[1024];


void plug_init(Plug *p) {
    plug = p;

    images[image_idx++] = LoadTexture("../assets/00.png");
    images[image_idx++] = LoadTexture("../assets/01.png");
    images[image_idx++] = LoadTexture("../assets/10.png");
    images[image_idx++] = LoadTexture("../assets/11.png");
}

void plug_post_reload(Plug *p) {
    plug_init(p);
}

void plug_draw() {
    plug->exit_window = WindowShouldClose();

    BeginDrawing();
    ClearBackground(DARKGRAY);

    size_t n_tile = (1 << plug->zoom_level);

    size_t tile_width = SCREEN_WIDTH / n_tile;
    size_t tile_height = SCREEN_HEIGHT / n_tile;

    for (size_t y = 0; y < n_tile; ++y) {
        for (size_t x = 0; x < n_tile; ++x) {
            DrawTexturePro(
                images[y*n_tile+x],
                (Rectangle){0, 0, 256, 256},
                (Rectangle){(float) tile_width*y, (float) tile_height*x, (float) tile_width, (float) tile_height},
                (Vector2){0, 0}, 0.0, WHITE);
        }
    }

    EndDrawing();
}

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation)
{
    switch (operation) {
        case CR_LOAD: 
            plug_init(static_cast<Plug *>(ctx->userdata));
            break;
        case CR_UNLOAD: 
            break;
        case CR_CLOSE: 
            break;
        case CR_STEP: 
            plug_draw();
            break;
    }

    return 0;
}
