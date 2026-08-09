#include "raylib.h"

#define HEIGHT 1000
#define WIDTH 1200

int main(void)
{   float i_cap=WIDTH/15.0f;
    float j_cap=HEIGHT/15.0f;

    Vector2 river ={0.0f,j_cap*2};
    Vector2 road={0.0f,j_cap*8};

    InitWindow(WIDTH,HEIGHT,"FROGGER");
    SetTargetFPS(60);


    while(!WindowShouldClose())
{

BeginDrawing();
ClearBackground((Color){0,0,0,255});
DrawRectangle(river.x,river.y,WIDTH,j_cap*5,(Color){0, 43, 77,255});
DrawRectangle(road.x,road.y,WIDTH,j_cap*5,(Color){0,0,0,255});





EndDrawing();



}




    CloseWindow();
    return 0;
}
