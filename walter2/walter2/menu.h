#pragma once
#include "raylib.h"

#define NUMBER_OF_BUTTONS   2

const int screenWidth = 1000;
const int screenHeight = 550;

typedef enum {
    PLAY,
    QUIT
};


static const char* processText[] = {
    "PLAY",
    "QUIT"
};

void newWindow()
{
    

    InitWindow(screenWidth, screenHeight, "PLAY WINDOW");

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);               
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("You are playing!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}

void menu(void)
{
    float recWidth = 220.0f;
    float recHeight = 60.0f;

    Rectangle toggleRecs[NUMBER_OF_BUTTONS] = { 0 };
    int mouseHoverRec = -1;

    int currentProcess = 0;
    bool textureReload = false;

    for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
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
        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
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
            case PLAY: newWindow();
                break;
            case QUIT: CloseWindow();
                break;
            }
        }

        BeginDrawing();

        ClearBackground(Color{0,4,35});


        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
            DrawRectangleRec(toggleRecs[i], ((i == mouseHoverRec)) ? MAGENTA : VIOLET);
            DrawRectangleLines((int)toggleRecs[i].x, (int)toggleRecs[i].y, (int)toggleRecs[i].width, (int)toggleRecs[i].height, PINK);
            DrawText(processText[i], (int)(toggleRecs[i].x + toggleRecs[i].width / 2 - MeasureText(processText[i] , 10) / 2 ) -25, (int)toggleRecs[i].y + 16, 30, WHITE);

        }
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


}