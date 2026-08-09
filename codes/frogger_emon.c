#include "raylib.h"

#define WIDTH 1200
#define HEIGHT 1000
#define bg_color (Color){144, 246, 144, 255}

int main(void)
{
    InitWindow(gw, gh, "Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
         BeginDrawing();
         ClearBackground(bg_color);

         EndDrawing();
    }
    CloseWindow();

    return 0;
}
