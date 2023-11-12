#pragma once

#include "raylib.h"
#include "sizes.h"
#include "menu.h"
#include "eColi.h"
#include "coronavirus.h"
#include "flu.h"
#include "ebola.h"
#include "test.h"
#include <vector>

void menu();
#define NUMBER_OF_PLAY_BUTTONS 6

typedef enum {
    CORONAVIRUS,
    ESHERICHIACOLI,
    EBOLA,
    FLU
}chooseAVirus;

typedef enum {
    BACK
}backButton;

typedef enum {
    TEST
}testButton;

static const char* testText = "Test your knowledge!";

static const char* processText[] = {
    "Coronavirus",
    "Esherichia coli",
    "Ebola Virus",
    "Flu"
};

static const char* backText = "Back";

void playMenu()
{
    bool isColideBack = false;
    int backCurrentProcess = 0;
    bool backTextureReload = false;

    bool testIsColide = false;
    int testCurrentProcess = 0;
    bool testTextureReload = false;

    float recWidth = 95.0f;
    float recHeight = 52.0f;

    
    Rectangle recBack = { screenWidth - recWidth -50, screenHeight - recHeight- 50,recWidth, recHeight };

    Rectangle recTest = { screenWidth /2 - recWidth -20 , screenHeight /2 - recHeight /2 ,recWidth+150, recHeight };


    std::vector<Rectangle> rects;

    for (int i = 0; i < 4; i++) {
        Rectangle rect;
        rect.width = 220;
        rect.height = 60;
        rect.x = (float)(190 + 650 * (i % 2));
        rect.y = (float)(265 + 300 * (i / 2));
        rects.push_back(rect);
    }

    int isColide = -1;
    bool textureReload = false;
    int currentProcess = 0;

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
            case CORONAVIRUS: coronavirus();
                break;
            case ESHERICHIACOLI: eColi();
                break;
            case EBOLA: ebolaVirus();
                break;
            case FLU: fluVirus();
                break;
            }
        }
        
        for (int i = 0; i < 1; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), recBack))
            {
                isColideBack = true;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    backTextureReload = true;
                    backCurrentProcess = BACK;
                }
                break;
            }
            else {
                isColideBack = false;
            }
        }
        if (backTextureReload) {
            if (backCurrentProcess == BACK) {
                menu();
                
            }
        }
        for (int i = 0; i < 1; i++)
        {
            if (CheckCollisionPointRec(GetMousePosition(), recTest))
            {
                testIsColide = true;
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    testTextureReload = true;
                    testCurrentProcess = BACK;
                }
                break;
            }
            else {
                testIsColide = false;
            }
        }
        if (testTextureReload) {
            if (testCurrentProcess == TEST) {
                test();

            }
        }
        

        BeginDrawing();

        ClearBackground(Color{ 0,4,35 });

        DrawRectangleRounded(recBack, 5, 1, ((isColideBack)) ? Color{ 176,0,24,255 }: Color{ 203,65,84,255 });
        DrawText(backText, recBack.x + (recBack.width - MeasureText(backText, 20)) / 2, recBack.y + (recBack.height - 20) / 2, 20, WHITE);
        
        DrawRectangleRounded(recTest, 5, 1, ((testIsColide)) ? DARKGREEN : GREEN);
        DrawText(testText, recTest.x + (recTest.width - MeasureText(backText, 20)) / 14, recTest.y + (recTest.height - 20) / 2, 20, WHITE);

        for (int i = 0; i < rects.size(); i++) {
            Rectangle lines = { (int)rects[i].x, (int)rects[i].y, (int)rects[i].width, (int)rects[i].height };
            DrawRectangleRounded(rects[i], 0.01, 1, ((i == isColide)) ? Color{ 27,222,210,255 } : Color{ 65,79,203,255 });
            DrawRectangleRoundedLines(lines, 0.1f, 1, 5, ((i == isColide)) ? Color{ 65,79,203,255 } : Color{ 27,222,210,255 });
            DrawText(processText[i], rects[i].x + (rects[i].width - MeasureText(processText[i], 20)) / 2, rects[i].y + (rects[i].height - 20) / 2, 20, WHITE);
        }
        
        EndDrawing();
    }

    CloseWindow();
}


