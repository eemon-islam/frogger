#include "raylib.h"
#include "raymath.h"

#define HEIGHT 1000
#define WIDTH 1200
typedef struct car
{
    float speed;
    float position_x;
    float position_y;
    float width;
    int pic_num;
}car;
typedef struct  turtle
{
    float speed;
    float position_x;
    float position_y;
    int pic_num;
}turtle;
typedef struct  logg
{
    float speed;
    float position_x;
    float position_y;
    float width;
    int pic_num;
}logg;


int main(void)
{   float i_cap=WIDTH/15.0f;
    float j_cap=HEIGHT/15.0f;

    Vector2 river ={0.0f,j_cap*2};
    Vector2 road={0.0f,j_cap*8};
    Vector2 frog_pos={8*i_cap,13*j_cap};

    Texture2D car_pic[5];
    Texture2D ground;
    Texture2D frog[2];
    Texture2D turtle_pic;
    Texture2D log_pic[3];


    InitWindow(WIDTH,HEIGHT,"FROGGER");
    SetTargetFPS(60);

    car_pic[0] = LoadTexture("asset/car_1.png");
    car_pic[1] = LoadTexture("asset/car_2.png");
    car_pic[2] = LoadTexture("asset/car_3.png");
    car_pic[3] = LoadTexture("asset/tractor.png");
    car_pic[4] = LoadTexture("asset/truck.png");
    ground = LoadTexture("asset/flower_ground_1.png");
    frog[0]= LoadTexture("asset/frog0000.png");
    frog[1]= LoadTexture("asset/frog0001.png");
    turtle_pic= LoadTexture("asset/turtle0000.png");
    log_pic[0]= LoadTexture("asset/log_left.png");
    log_pic[1]= LoadTexture("asset/log_middle.png");
    log_pic[2]= LoadTexture("asset/log_right.png");
    

    car cars[14];
    turtle turtles[20];
    logg logs[4*3+9*2+6*3];



    int car_idx=0;
    int tur_idx=0;
    int log_idx=0;

    for(int i=0;i<2;i++)
    {
        cars[car_idx].pic_num=4;
        cars[car_idx].speed=-100.0f;
        cars[car_idx].position_x=(8+5*i)*i_cap;
        cars[car_idx].position_y=8*j_cap;
        cars[car_idx].width=2*i_cap;
        car_idx++;
        
    }
    for(int i=0;i<3;i++)
    {
        cars[car_idx].pic_num=2;
         cars[car_idx].speed=+120.0f;
        cars[car_idx].position_x=(1+5*i)*i_cap;
        cars[car_idx].position_y=9*j_cap;   
        cars[car_idx].width=i_cap;      
        car_idx++;
    }
    for(int i=0;i<3;i++)
    {
    cars[car_idx].pic_num=1;
     cars[car_idx].speed=-200.0f;
        cars[car_idx].position_x=(4+4*i)*i_cap;
        cars[car_idx].position_y=10*j_cap; 
        cars[car_idx].width=i_cap;     
    car_idx++;

    }
    for(int i=0;i<3;i++)
    {
        cars[car_idx].pic_num=3;
         cars[car_idx].speed=+150.0f;        
        cars[car_idx].position_x=(6+4*i)*i_cap;
        cars[car_idx].position_y=11*j_cap;
        cars[car_idx].width=i_cap;  
        car_idx++;       
    }    
    for(int i=0;i<3;i++)
    {
        cars[car_idx].pic_num=0;
         cars[car_idx].speed=-130.0f;
        cars[car_idx].position_x=(2+4*i)*i_cap;
        cars[car_idx].position_y=12*j_cap;  
        cars[car_idx].width=i_cap;        
        car_idx++;
    }
    for(int j=0;j<2;j++)    
    {
        for(int i=0;i<4;i++)
        {
            turtles[tur_idx].speed=-120.0f;
            turtles[tur_idx].position_x=3+(4*i+j)*i_cap;
            turtles[tur_idx].position_y=3*j_cap;
            tur_idx++;
        }
    }
    for(int j=0;j<3;j++)    
    {
        for(int i=0;i<4;i++)
        {
            turtles[tur_idx].speed=-120.0f;
            turtles[tur_idx].position_x=(4*i+j)*i_cap;
            turtles[tur_idx].position_y=6*j_cap;
            tur_idx++;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            logs[log_idx].speed=100.0f;
            if(j==0)
            {logs[log_idx].pic_num=0;}
            else if(j==3)
            {
                logs[log_idx].pic_num=2;
            }
            else{
                logs[log_idx].pic_num=1;
            }
            logs[log_idx].position_x=(1+5*i+j)*i_cap;
            logs[log_idx].position_y=2*j_cap;
            log_idx++;
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<9;j++)
        {
            logs[log_idx].speed=120.0f;
            if(j==0)
            {logs[log_idx].pic_num=0;}
            else if(j==8)
            {
                logs[log_idx].pic_num=2;
            }
            else{
                logs[log_idx].pic_num=1;
            }
            logs[log_idx].position_x=(2+12*i+j)*i_cap;
            logs[log_idx].position_y=4*j_cap;
            log_idx++;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            logs[log_idx].speed=120.0f;
            if(j==0)
            {logs[log_idx].pic_num=0;}
            else if(j==4)
            {
                logs[log_idx].pic_num=2;
            }
            else{
                logs[log_idx].pic_num=1;
            }
            logs[log_idx].position_x=(2+12*i+j)*i_cap;
            logs[log_idx].position_y=5*j_cap;
            log_idx++;
        }
    }




    float frog_rot=0.0f;
    while(!WindowShouldClose())
{
float dt=GetFrameTime();

        for (int i= 0; i < car_idx; i++) 
        {
            cars[i].position_x+=cars[i].speed*dt;
            if (cars[i].speed > 0 && cars[i].position_x > WIDTH) {
                cars[i].position_x=-cars[i].width;
            } 
            else if (cars[i].speed < 0 && cars[i].position_x+cars[i].width < 0) {
                cars[i].position_x = WIDTH+cars[i].width;   
            }
        }

        for (int i= 0; i < tur_idx; i++) 
        {
            turtles[i].position_x+=turtles[i].speed*dt;

            if (  turtles[i].position_x+i_cap < 0) {
                turtles[i].position_x = WIDTH+i_cap;   
            }
        }     
        for (int i= 0; i < log_idx; i++) 
        {
            logs[i].position_x+=logs[i].speed*dt;

            if (  logs[i].position_x > WIDTH) {
                logs[i].position_x = -i_cap;   
            }
        }                  
        if (IsKeyPressed(KEY_UP)) {
            frog_pos.y -= j_cap;
            frog_rot = 0.0f;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            frog_pos.y += j_cap;
            frog_rot = 180.0f;
        }
        if (IsKeyPressed(KEY_LEFT)) {
            frog_pos.x -= i_cap;
            frog_rot = 270.0f;
        }
        if (IsKeyPressed(KEY_RIGHT)) {
            frog_pos.x += j_cap;
            frog_rot = 90.0f;
        }


BeginDrawing();
ClearBackground((Color){0,0,0,255});
DrawRectangle(river.x,river.y,WIDTH,j_cap*5,(Color){0, 43, 77,255});
DrawRectangle(road.x,road.y,WIDTH,j_cap*5,(Color){0,0,0,255});
for(int i=0;i<car_idx;i++)
{
  DrawTexturePro(car_pic[cars[i].pic_num],(Rectangle){0.0f,0.0f,car_pic[cars[i].pic_num].width,car_pic[cars[i].pic_num].height},(Rectangle){cars[i].position_x,cars[i].position_y,cars[i].width,j_cap},Vector2Zero(),0.0f,WHITE);
}
for(int i=0;i<log_idx;i++)
{
  DrawTexturePro(log_pic[logs[i].pic_num],(Rectangle){0.0f,0.0f,log_pic[logs[i].pic_num].width,log_pic[logs[i].pic_num].height},(Rectangle){logs[i].position_x,logs[i].position_y,i_cap,j_cap},Vector2Zero(),0.0f,WHITE);
}
for(int i=0;i<tur_idx;i++)
{
  DrawTexturePro(turtle_pic,(Rectangle){0.0f,0.0f,turtle_pic.width,turtle_pic.height},(Rectangle){turtles[i].position_x,turtles[i].position_y,i_cap,j_cap},Vector2Zero(),0.0f,WHITE);
}
int pos_x=0;
for(int i=0;i<15;i++)
{
    DrawTexturePro(ground,(Rectangle){0.0f,0.0f,ground.width,ground.height},(Rectangle){pos_x,7*j_cap,i_cap,j_cap},Vector2Zero(),0.0f,WHITE);
    pos_x+=i_cap;
}
 pos_x=0;
for(int i=0;i<15;i++)
{
    DrawTexturePro(ground,(Rectangle){0.0f,0.0f,ground.width,ground.height},(Rectangle){pos_x,13*j_cap,i_cap,j_cap},Vector2Zero(),0.0f,WHITE);
    pos_x+=i_cap;
}
DrawTexturePro(frog[0],(Rectangle){0.0f,0.0f,frog[0].width,frog[0].height},(Rectangle){frog_pos.x,frog_pos.y,i_cap,j_cap},Vector2Zero(),frog_rot,WHITE);



EndDrawing();



}


    for(int i=0;i<5;i++)
    {
        UnloadTexture(car_pic[i]);
    }
    for(int i=0;i<3;i++)
    {
        UnloadTexture(log_pic[i]);
    }
    UnloadTexture(frog[0]);
    UnloadTexture(frog[1]);
    UnloadTexture(turtle_pic);
    CloseWindow();
    return 0;
}
