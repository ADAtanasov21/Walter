#pragma once
#include "raylib.h"

const int screenWidth = 1000;
const int screenHeight = 550;
#define NUMBER_OF_PLAY_BUTTONS 3
void someVirus() 
{
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
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

        DrawText("Ne", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    
}



typedef enum {
    coronavirus,
    hiv,
    esherichiaColi,
    ebolaVirus,
    adenovirus,
    flu
}chooseTheVirus;


static const char* processText[] = {
    "Coronavirus",
    "HIV",
    "Esherichia coli",
    "Ebola Virus",
    "Adenovirus",
    "Flu"
};




void playMenu()
{

    float recWidth = 220.0f;
    float recHeight = 60.0f;

    Rectangle toggleRecs[NUMBER_OF_PLAY_BUTTONS] = { 0 };
    int mouseHoverRec = -1;

    int currentProcess = 0;
    bool textureReload = false;

    for (int i = 0; i < NUMBER_OF_PLAY_BUTTONS; i++) {
        toggleRecs[i] = Rectangle{ screenWidth / 2 +100, (float)(screenHeight / 2 + 100 * i - 100), recWidth, recHeight };

    }

    InitWindow(screenWidth, screenHeight, "PLAY WINDOW");

    SetTargetFPS(60);
    
    
    while (!WindowShouldClose())
    {
        for (int i = 0; i < NUMBER_OF_PLAY_BUTTONS; i++)
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
            case coronavirus: someVirus();
                break;
            case hiv: someVirus();
                break;
            case esherichiaColi: someVirus();
                break;
            case ebolaVirus: someVirus();
                break;
            case adenovirus: someVirus();
                break;
            case flu: someVirus();
                break;
            }
        }

        BeginDrawing();

        ClearBackground(Color{ 0,4,35 });

        

        for (int i = 0; i < NUMBER_OF_PLAY_BUTTONS; i++)
        {
            DrawRectangleRec(toggleRecs[i], ((i == mouseHoverRec)) ? MAGENTA : VIOLET);
            DrawRectangleLines((int)toggleRecs[i].x, (int)toggleRecs[i].y, (int)toggleRecs[i].width, (int)toggleRecs[i].height, PINK);
            DrawText(processText[i], (int)(toggleRecs[i].x + toggleRecs[i].width / 2 - MeasureText(processText[i], 10) / 2) - 25, (int)toggleRecs[i].y + 16, 30, WHITE);

        }
        EndDrawing();
        
    }

    CloseWindow();
}