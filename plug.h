#include <cstdint>

#ifndef PLUG_H
#define PLUG_H

constexpr const int SCREEN_WIDTH         = 1100;
constexpr const int SCREEN_HEIGHT        = 800;

typedef struct Plug {
    uint8_t zoom_level = 1;
    bool exit_window;
} Plug;

#endif // PLUG_H
