#pragma once

#include "raylib.h"
#include "sizes.h"
#include "playMenu.h"


void fluVirus()
{
    int isColideBackPlay = -1;
    bool backPlayTextureReload = false;
    int currentProcesBackTest = 0;

    float recWidth = 95.0f;
    float recHeight = 52.0f;

    Rectangle recBackAndTest[NUMBER_TEST_AND_BACK] = { 0 };
    for (int i = 0; i < NUMBER_TEST_AND_BACK; i++) {
        recBackAndTest[i] = Rectangle{ screenWidth - recWidth - 100 + 100 * i , screenHeight - recHeight - 50,recWidth, recHeight };
    }


    Camera camera = { 0 };
    camera.position = Vector3{ 6.0f, 7.0f, 6.0f };
    camera.target = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model model = LoadModel("resources/models/fluFiles/flu.obj");


    Vector3 position = { 0.0f, 0.0f, 0.0f };

    char name[] = "Flu";
    char symptomps[] = "Symptoms:";
    char infoSymptomps[] = "Hight temperature; Muscle or\nbody aches; Headache; Cought;\nSore throat;";
    char cures[] = "Treatment:";
    char infoCures[] = "Rest; Drinking liquids;\nBathing with warm water;\nMedicines for flu";
    char dangers[] = "Dangers:";
    char infoDangers[] = "You may have pneumonia;\nKidney diseases;\nIt can give you heart problems.";

    Rectangle rect = { screenWidth - screenWidth / 4 - 150,0,screenWidth / 4 + 150, screenHeight };
    SetTargetFPS(60);

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

        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();

        ClearBackground(Color{ 0,4,35,255 });

        BeginMode3D(camera);
        DrawModel(model, position, 1.0f, Color{155,186,228,255});
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawRectangleRec(rect, Color{ 27,222,210,255 });
        DrawText(name, rect.x + 30, rect.y + 50, 55, WHITE);
        DrawText(symptomps, rect.x + 30, rect.y + 130, 35, WHITE);
        DrawText(infoSymptomps, rect.x + 30, rect.y + 180, 20, WHITE);
        DrawText(cures, rect.x + 30, rect.y + 280, 35, WHITE);
        DrawText(infoCures, rect.x + 30, rect.y + 330, 20, WHITE);
        DrawText(dangers, rect.x + 30, rect.y + 450, 35, WHITE);
        DrawText(infoDangers, rect.x + 30, rect.y + 500, 20, WHITE);

        for (int i = 0; i < NUMBER_TEST_AND_BACK; i++) {
            DrawRectangleRounded(recBackAndTest[i], 5, 1, ((isColideBackPlay == i)) ? Color{ 176,0,24,255 } : Color{ 203,65,84,255 });
            DrawText(backPlayText[i], recBackAndTest[i].x + (recBackAndTest[i].width - MeasureText(backPlayText[i], 20)) / 2, recBackAndTest[i].y + (recBackAndTest[i].height - 20) / 2, 20, WHITE);
        }

        EndDrawing();
    }

    UnloadModel(model);
    //UnloadTexture(texture);
    CloseWindow();
}