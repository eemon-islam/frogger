#include "raylib.h"
#include "raymath.h"

#define HEIGHT 1000
#define WIDTH 1200
typedef struct Car
{
    float speed;
    float position_x;
    float position_y;
    float width;
    int pic_num;
}Car;


int main(void)
{   float i_cap=WIDTH/15.0f;
    float j_cap=HEIGHT/15.0f;

    Vector2 river ={0.0f,j_cap*2};
    Vector2 road={0.0f,j_cap*8};

    Texture2D car_pic[5];


    InitWindow(WIDTH,HEIGHT,"FROGGER");
    SetTargetFPS(60);

    car_pic[0] = LoadTexture("asset/car_1.png");
    car_pic[1] = LoadTexture("asset/car_2.png");
    car_pic[2] = LoadTexture("asset/car_3.png");
    car_pic[3] = LoadTexture("asset/tractor.png");
    car_pic[4] = LoadTexture("asset/truck.png");

    Car cars[14];
    int idx=0;
    for(int i=0;i<2;i++)
    {
        cars[idx].pic_num=4;
        cars[idx].speed=-100.0f;
        cars[idx].position_x=(8+4*i)*i_cap;
        cars[idx].position_y=8*j_cap;
        cars[idx].width=2*i_cap;
        idx++;
        
    }
    for(int i=0;i<3;i++)
    {
        cars[idx].pic_num=2;
         cars[idx].speed=+120.0f;
        cars[idx].position_x=(5+3*i)*i_cap;
        cars[idx].position_y=9*j_cap;   
        cars[idx].width=i_cap;      
        idx++;
    }
    for(int i=0;i<3;i++)
    {
    cars[idx].pic_num=1;
     cars[idx].speed=-200.0f;
        cars[idx].position_x=(4+4*i)*i_cap;
        cars[idx].position_y=10*j_cap; 
        cars[idx].width=i_cap;     
    idx++;

    }
    for(int i=0;i<3;i++)
    {
        cars[idx].pic_num=3;
         cars[idx].speed=+150.0f;        
        cars[idx].position_x=(6+4*i)*i_cap;
        cars[idx].position_y=11*j_cap;
        cars[idx].width=i_cap;  
        idx++;       
    }    
    for(int i=0;i<3;i++)
    {
        cars[idx].pic_num=0;
         cars[idx].speed=-130.0f;
        cars[idx].position_x=(2+4*i)*i_cap;
        cars[idx].position_y=12*j_cap;  
        cars[idx].width=i_cap;        
        idx++;
    }
    while(!WindowShouldClose())
{


BeginDrawing();
ClearBackground((Color){0,0,0,255});
DrawRectangle(river.x,river.y,WIDTH,j_cap*5,(Color){0, 43, 77,255});
DrawRectangle(road.x,road.y,WIDTH,j_cap*5,(Color){0,0,0,255});
for(int i=0;i<idx;i++)
{
  DrawTexturePro(car_pic[cars[i].pic_num],(Rectangle){0.0f,0.0f,car_pic[cars[i].pic_num].width,car_pic[cars[i].pic_num].height},(Rectangle){cars[i].position_x,cars[i].position_y,cars[i].width,j_cap},Vector2Zero(),0.0f,WHITE);
}





EndDrawing();



}


    for(int i=0;i<5;i++)
    {
        UnloadTexture(car_pic[i]);
    }

    CloseWindow();
    return 0;
}
