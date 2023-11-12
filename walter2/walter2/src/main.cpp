#include "raylib.h"
#include "menu.h"

int main()
{
    InitWindow(screenWidth, screenHeight, "HOME");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        menu();
        
        EndDrawing();
    }

    CloseWindow(); 
}