#include "raylib.h"
#include "menu.h"



int main(void)
{

    InitWindow(screenWidth, screenHeight, "HOME");

    SetTargetFPS(60);

    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);
        menu();
        
        EndDrawing();
    }

    
    CloseWindow();
    

    
}