#pragma once
#include "raylib.h"
#include "sizes.h"
#include "playMenu.h"

void coronavirus()
{
    // Variables for handling button interaction
    int isColideBackPlay = -1;
    bool backPlayTextureReload = false;
    int currentProcesBackTest = 0;

    //Set the size of the button
    float recWidth = 95.0f;
    float recHeight = 52.0f;

    //Array of the rectangle for back and test buttons
    Rectangle recBackAndTest[NUMBER_BACK] = { 0 };
    for (int i = 0; i < NUMBER_BACK; i++) {
        recBackAndTest[i] = Rectangle{ screenWidth - recWidth - 100 + 100 * i , screenHeight - recHeight - 50,recWidth, recHeight };
    }

    //Set the camera for 3D rendaring
    Camera camera = { 0 };
    camera.position = Vector3{ 6.0f, 7.0f, 6.0f };
    camera.target = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    //Load 3D model
    Model model = LoadModel("resources/models/coronavirusFiles/coronavirus.obj");
    
    //Initial position for the 3D model
    Vector3 position = { 0.0f, 0.0f, 0.0f };

    //Information for displaying in the sidebar
    char name[] = "Coronavirus";
    char symptomps[] = "Symptoms:";
    char infoSymptomps[] = "Fever or chills; Cough; Fatigue;\nMuscle or body aches; Headache;";
    char cures[] = "Treatment:";
    char infoCures[] = "Take antibiotics;\nStay izolied\nBathing with warm water;";
    char dangers[] = "Dangers:";
    char infoDangers[] = "You may have pneumonia;\nTo lose taste and smell;\nIt can give you heart problems.";

    //Rectangle for the sidebar
    Rectangle rect = { screenWidth - screenWidth / 4 - 150,0,screenWidth / 4 + 150, screenHeight };

    while (!WindowShouldClose())
    {
        
        for (int i = 0; i < NUMBER_BACK; i++)
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
        //Process button click
        if (backPlayTextureReload) {
            switch (currentProcesBackTest) {
            case BACKPLAY: playMenu();
                break;
            }
        }

        //Update 3D camera
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();

        ClearBackground(Color{ 0,4,35,255 });

        //Begin 3D rendering mode
        BeginMode3D(camera);
            DrawModel(model, position, 1.0f, Color{127, 29, 29,255});
            DrawGrid(10, 1.0f);
        EndMode3D();

        //Draw the sidebar with information
        DrawRectangleRec(rect, Color{ 27,222,210,255 });
        DrawText(name, rect.x + 30, rect.y + 50, 55, WHITE);
        DrawText(symptomps, rect.x + 30, rect.y + 130, 35, WHITE);
        DrawText(infoSymptomps, rect.x + 30, rect.y + 180, 20, WHITE);
        DrawText(cures, rect.x + 30, rect.y + 280, 35, WHITE);
        DrawText(infoCures, rect.x + 30, rect.y + 330, 20, WHITE);
        DrawText(dangers, rect.x + 30, rect.y + 550, 35, WHITE);
        DrawText(infoDangers, rect.x + 30, rect.y + 600, 20, WHITE);

        //Draw back and test buttons
        for (int i = 0; i < NUMBER_BACK; i++) {
            DrawRectangleRounded(recBackAndTest[i], 5, 1, ((isColideBackPlay == i)) ? Color{ 176,0,24,255 } : Color{ 203,65,84,255 });
            DrawText(backPlayText[i], recBackAndTest[i].x + (recBackAndTest[i].width - MeasureText(backPlayText[i], 20)) / 2, recBackAndTest[i].y + (recBackAndTest[i].height - 20) / 2, 20, WHITE);
        }

        EndDrawing();
    }
    //Unload 3D model and close the window
    UnloadModel(model);
    CloseWindow();
}