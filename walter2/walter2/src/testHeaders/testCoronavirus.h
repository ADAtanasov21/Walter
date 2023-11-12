#pragma once
#include "sizes.h"
#include "raylib.h"


void testCoronaVirus()
{

    while (!WindowShouldClose())
    {
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    
    }

    CloseWindow();
    
}