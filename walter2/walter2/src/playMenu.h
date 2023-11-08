#pragma once
#include "raylib.h"
#include "bacteriophager.h"
#include "flu.h"
#include "ebola.h"
#include <vector>
#include "sizes.h"


#define NUMBER_OF_PLAY_BUTTONS 6
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
    bacteriophager,
    esherichiaColi,
    ebola,
    adenovirus,
    flu
};


static const char* processText[] = {
    "Coronavirus",
    "Bacteriophager",
    "Esherichia coli",
    "Ebola Virus",
    "Adenovirus",
    "Flu"
};

void playMenu()
{
    std::vector<Rectangle> rects;
    

    for (int i = 0; i < 6; i++) {
        Rectangle rect;
        rect.width = 220;
        rect.height = 60;
        rect.x = (float)(235 + 280 * (i % 3));
        rect.y = (float)(230 + 260 * (i / 3));
        rects.push_back(rect);
    }

    int isColide = -1;
    bool textureReload = false;
    int currentProcess = 0;

    
    InitWindow(screenWidth, screenHeight, "Ivan");

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        for (int i = 0; i < rects.size(); i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), rects[i]))
            {
                isColide = i;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    currentProcess = i;
                    textureReload = true;

                }
                break;
            }
            else isColide = -1;
        }
        if (textureReload)
        {
            switch (currentProcess)
            {
            case coronavirus: someVirus();
                break;
            case bacteriophager: bacteriophagerVirus();
                break;
            case esherichiaColi: someVirus();
                break;
            case ebola: ebolaVirus();
                break;
            case adenovirus: someVirus();
                break;
            case flu: fluVirus();
                break;
            }
        }
            

        BeginDrawing();

        ClearBackground(Color{ 0,4,35 });

        
        for (int i = 0; i < rects.size(); i++) {
            DrawRectangleRec(rects[i], (isColide == i) ? BLUE : SKYBLUE);
            DrawRectangleLines((float)rects[i].x, (float)rects[i].y, (float)rects[i].width, (float)rects[i].height, ((i == currentProcess) || (i == isColide)) ? BLUE : GRAY);
            DrawText(processText[i], rects[i].x + (rects[i].width - MeasureText(processText[i], 20)) / 2, rects[i].y + (rects[i].height - 20) / 2, 20, WHITE);
        }
        
        EndDrawing();
    
    }

    CloseWindow();

}