#pragma once
#include "raylib.h"
#include "sizes.h"
#include "playMenu.h"
#define NUMBER_OF_MAIN_BUTTONS   2

typedef enum {
    PLAY,
    QUIT
}exitOrPlay;

static const char* processTextMainMenu[] = {
    "PLAY",
    "QUIT"
};

void menu()
{
    float recWidth = 220.0f;
    float recHeight = 60.0f;

    Rectangle toggleRecs[NUMBER_OF_MAIN_BUTTONS] = { 0 };
    int mouseHoverRec = -1;

    int currentProcess = 0;
    bool textureReload = false;

    for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++) {
        toggleRecs[i] = Rectangle{ screenWidth/2 - recWidth / 2, (float)(screenHeight/2 + 100 * i - recHeight/2) + 110, recWidth, recHeight };
        
    }

    

    Image image = LoadImage("resources/images/logo.png");
    Texture2D texture = LoadTextureFromImage(image);
    
    UnloadImage(image);

    SetTargetFPS(60);

    while (!WindowShouldClose())
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
            else {
                mouseHoverRec = -1;
            }
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

        ClearBackground(Color{0,4,35,255});

        DrawTexture(texture, screenWidth/2 - texture.width/2+5, screenHeight/2 - texture.height/1.3,WHITE);
        
        for (int i = 0; i < NUMBER_OF_MAIN_BUTTONS; i++)
        {
            Rectangle lines = { (int)toggleRecs[i].x, (int)toggleRecs[i].y, (int)toggleRecs[i].width, (int)toggleRecs[i].height };
            DrawRectangleRounded(toggleRecs[i], 0.01, 1,((i == mouseHoverRec)) ?  Color{134,53,197,255}:  Color{ 185,167,239,255 });
            DrawRectangleRoundedLines(lines, 0.1f,1 ,5,((i == mouseHoverRec)) ?  Color{ 255,120,209,255 }: Color{ 94,84,123,255 });
            DrawText(processTextMainMenu[i], (float)(toggleRecs[i].x + toggleRecs[i].width / 2 - MeasureText(processTextMainMenu[i] , 10) / 2 ) -25, (int)(toggleRecs[i].y) + 16, 30, WHITE);
        }

        EndDrawing();
    }
    UnloadTexture(texture);

    
    CloseWindow();
}