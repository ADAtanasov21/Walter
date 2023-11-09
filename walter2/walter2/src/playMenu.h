#pragma once
#include "raylib.h"
#include "eColi.h"
#include "coronavirus.h"
#include "flu.h"
#include "ebola.h"
#include <vector>
#include "sizes.h"

#define NUMBER_OF_PLAY_BUTTONS 6

typedef enum {
    CORONAVIRUS,
    ESHERICHIACOLI,
    EBOLA,
    FLU
};

static const char* processText[] = {
    "Coronavirus",
    "Esherichia coli",
    "Ebola Virus",
    "Flu"
};

void playMenu()
{
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
            
        BeginDrawing();

        ClearBackground(Color{ 0,4,35 });

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