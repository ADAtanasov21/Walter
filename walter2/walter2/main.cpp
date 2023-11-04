#include "raylib.h"
#include "headers/menu.h"



int main(void)
{

    InitWindow(screenWidth, screenHeight, "HOME");

    SetTargetFPS(60);

    
    while (!WindowShouldClose())
    {
        menu();
        
        EndDrawing();
    }

    
    CloseWindow();
    

    
}