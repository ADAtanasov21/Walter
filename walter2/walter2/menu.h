#pragma once
#include "raylib.h"
#include "headers/playMenu.h"

#define NUMBER_OF_MAIN_BUTTONS   2


typedef enum {
    PLAY,
    QUIT
}exitOrPlay;


static const char* processTextMainMenu[] = {
    "PLAY",
    "QUIT"
};



void menu(void)
{

    //Image imOrigin = LoadImage("resorces/logo.png");
    float recWidth = 220.0f;
    float recHeight = 60.0f;

    Rectangle toggleRecs[NUMBER_OF_MAIN_BUTTONS] = { 0 };
    int mouseHoverRec = -1;

    int currentProcess = 0;
    bool textureReload = false;

    for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++) {
        toggleRecs[i] = Rectangle{ screenWidth/2 - recWidth / 2, (float)(screenHeight/2 + 100 * i - recHeight/2), recWidth, recHeight };
        
    }

    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "HOME");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), toggleRecs[i]))
            {
                mouseHoverRec = i;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    currentProcess = i;
                    textureReload = true;

                }
                break;
            }
            else mouseHoverRec = -1;
        }
        if (textureReload) {
            switch (currentProcess)
            {
            case PLAY: playMenu();
                break;
            case QUIT: CloseWindow();
                break;
            }
        }

        BeginDrawing();

        ClearBackground(Color{0,4,35});


        for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++)
        {
            DrawRectangleRec(toggleRecs[i], ((i == mouseHoverRec)) ? MAGENTA : VIOLET);
            DrawRectangleLines(toggleRecs[i].x, toggleRecs[i].y, toggleRecs[i].width, toggleRecs[i].height, PINK);
            DrawText(processTextMainMenu[i], (toggleRecs[i].x + toggleRecs[i].width / 2 - MeasureText(processTextMainMenu[i] , 10) / 2 ) -25, (int)toggleRecs[i].y + 16, 30, WHITE);

        }
        

        EndDrawing();
        
    }

    CloseWindow();

}