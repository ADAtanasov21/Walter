#pragma once
#include "raylib.h"
#include "sizes.h"
void ebolaVirus()
{
    InitWindow(screenWidth, screenHeight, "Ebola virus");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Ne", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
}