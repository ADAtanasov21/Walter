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
    //Variables for handing back button interaction
    bool isColideBack = false;
    int backCurrentProcess = 0;
    bool backTextureReload = false;

    //Variable for handling test button interaction
    bool testIsColide = false;
    int testCurrentProcess = 0;
    bool testTextureReload = false;

    //Dimensions for buttons
    float recWidth = 95.0f;
    float recHeight = 52.0f;

    //Rectangle for the back button 
    Rectangle recBack = { screenWidth - recWidth -50, screenHeight - recHeight- 50,recWidth, recHeight };

    //Rectangle for the test button 
    Rectangle recTest = { screenWidth /2 - recWidth -35 , screenHeight /2 - recHeight /2 ,recWidth+150, recHeight };

    //Vactor to store rectangles for virus buttons
    std::vector<Rectangle> rects;

    //Initialize virus buutons rectangles
    for (int i = 0; i < 4; i++) {
        Rectangle rect;
        rect.width = 220;
        rect.height = 60;
        rect.x = (float)(190 + 650 * (i % 2));
        rect.y = (float)(265 + 300 * (i / 2));
        rects.push_back(rect);
    }

    //Varaible for handling virus button interaction
    int isColide = -1;
    bool textureReload = false;
    int currentProcess = 0;

    //Load textures for viruses
    Image imageCorona = LoadImage("resources/images/coronaVi.png");
    Texture2D textureCorona = LoadTextureFromImage(imageCorona);

    Image imageFlu = LoadImage("resources/images/flu.png");
    Texture2D textureFlu = LoadTextureFromImage(imageFlu);

    Image imageEColi = LoadImage("resources/images/eColi.png");
    Texture2D textureEColi = LoadTextureFromImage(imageEColi);
    
    Image imageEbola = LoadImage("resources/images/ebola.png");
    Texture2D textureEbola = LoadTextureFromImage(imageEbola);

    while (!WindowShouldClose())
    {
        for (int i = 0; i < rects.size(); i++)
        {
            //Check collision on virus buttons
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
        //Process virus button click
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

        //Check collision on back button
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
        //Process back button click
        if (backTextureReload) {
            if (backCurrentProcess == BACK) {
                menu();
                
            }
        }
        //Check collision on test button
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
        //Process test button click
        if (testTextureReload) {
            if (testCurrentProcess == TEST) {
                test();

            }
        }
        

        BeginDrawing();

        ClearBackground(Color{ 0,4,35 });

        //Draw virus images
        DrawTexture(textureCorona, 200, 40, WHITE);
        DrawTexture(textureEColi, screenWidth - textureFlu.width * 2 - 15, 90, WHITE);
        DrawTexture(textureFlu, screenWidth - textureFlu.width * 2 - 15, screenHeight - textureFlu.height * 2 - 70, WHITE);
        DrawTexture(textureEbola, 200, screenHeight - textureFlu.height * 2 - 70, WHITE);
        
        //Draw back button
        DrawRectangleRounded(recBack, 5, 1, ((isColideBack)) ? Color{ 176,0,24,255 }: Color{ 203,65,84,255 });
        DrawText(backText, recBack.x + (recBack.width - MeasureText(backText, 20)) / 2, recBack.y + (recBack.height - 20) / 2, 20, WHITE);
        
        //Draw test button
        DrawRectangleRounded(recTest, 5, 1, ((testIsColide)) ? DARKGREEN : GREEN);
        DrawText(testText, recTest.x + (recTest.width - MeasureText(backText, 20)) / 14, recTest.y + (recTest.height - 20) / 2, 20, WHITE);

        //Draw virus buttons
        for (int i = 0; i < rects.size(); i++) {
            Rectangle lines = { (int)rects[i].x, (int)rects[i].y, (int)rects[i].width, (int)rects[i].height };
            DrawRectangleRounded(rects[i], 0.01, 1, ((i == isColide)) ? Color{ 27,222,210,255 } : Color{ 65,79,203,255 });
            DrawRectangleRoundedLines(lines, 0.1f, 1, 5, ((i == isColide)) ? Color{ 65,79,203,255 } : Color{ 27,222,210,255 });
            DrawText(processText[i], rects[i].x + (rects[i].width - MeasureText(processText[i], 20)) / 2, rects[i].y + (rects[i].height - 20) / 2, 20, WHITE);
        }
        
        EndDrawing();
    }
    //Unload textures
    UnloadTexture(textureCorona);
    UnloadTexture(textureFlu);
    UnloadTexture(textureEColi);
    UnloadTexture(textureEbola);
    
    CloseWindow();
}