#pragma once
#include "raylib.h"
#include "sizes.h"

void score() {
    
    int isColideBackPlay = -1;
    bool backPlayTextureReload = false;
    int currentProcesBackTest = 0;

    float recWidth = 95.0f;
    float recHeight = 52.0f;

    Rectangle recBackAndTest[NUMBER_TEST_AND_BACK] = { 0 };
    for (int i = 0; i < NUMBER_TEST_AND_BACK; i++) {
        recBackAndTest[i] = Rectangle{ screenWidth - recWidth - 100 + 100 * i , screenHeight - recHeight - 50,recWidth, recHeight };
    }
   
    while (!WindowShouldClose())    
    {
        for (int i = 0; i < NUMBER_TEST_AND_BACK; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), recBackAndTest[i]))
            {
                isColideBackPlay = i;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    currentProcesBackTest = i;
                    backPlayTextureReload = true;

                }
                break;
            }
            else {
                isColideBackPlay = -1;
            }
        }
        if (backPlayTextureReload) {
            switch (currentProcesBackTest) {
            case BACKPLAY: playMenu();
                break;
            }
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    
}