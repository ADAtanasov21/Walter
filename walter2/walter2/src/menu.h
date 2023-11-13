#pragma once
#include "raylib.h"
#include "sizes.h"
#include "playMenu.h"

//Number of buttons
#define NUMBER_OF_MAIN_BUTTONS   2

//Enumeration to represent main menu options
typedef enum {
    PLAY,
    QUIT
}exitOrPlay;

// Array to store text for main menu buttons
static const char* processTextMainMenu[] = {
    "PLAY",
    "QUIT"
};

void menu()
{
    //Dimension for menu buttons
    float recWidth = 220.0f;
    float recHeight = 60.0f;

    //Array of rectangles for menu buttons
    Rectangle toggleRecs[NUMBER_OF_MAIN_BUTTONS] = { 0 };
    
    //Varaiable to track which button the mouse is hovering over
    int mouseHoverRec = -1;

    // Variables for habdling button clicks
    int currentProcess = 0;
    bool textureReload = false;

    // Initialize rectangles for menu buttons
    for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++) {
        toggleRecs[i] = Rectangle{ screenWidth/2 - recWidth / 2, (float)(screenHeight/2 + 100 * i - recHeight/2) + 110, recWidth, recHeight };
        
    }

    // Load logo image
    Image image = LoadImage("resources/images/logo.png");
    Texture2D texture = LoadTextureFromImage(image);
    
    while (!WindowShouldClose())
    {
        //Check collision with menu buttons
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
            else {
                mouseHoverRec = -1;
            }
        }
        //Process button click
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

        ClearBackground(Color{0,4,35,255});

        //Draw logo texture
        DrawTexture(texture, screenWidth/2 - texture.width/2+5, screenHeight/2 - texture.height/1.3,WHITE);
        
        //Draw menu buttons
        for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++)
        {
            Rectangle lines = { (int)toggleRecs[i].x, (int)toggleRecs[i].y, (int)toggleRecs[i].width, (int)toggleRecs[i].height };
            
            //Draw button background
            DrawRectangleRounded(toggleRecs[i], 0.01, 1,((i == mouseHoverRec)) ?  Color{134,53,197,255}:  Color{ 185,167,239,255 });
            DrawRectangleRoundedLines(lines, 0.1f,1 ,5,((i == mouseHoverRec)) ?  Color{ 255,120,209,255 }: Color{ 94,84,123,255 });
            DrawText(processTextMainMenu[i], (float)(toggleRecs[i].x + toggleRecs[i].width / 2 - MeasureText(processTextMainMenu[i] , 10) / 2 ) -25, (int)(toggleRecs[i].y) + 16, 30, WHITE);
        }
        EndDrawing();
    }
    //Unload the logo texture
    UnloadTexture(texture);

    CloseWindow();
}