#pragma once
#include "raylib.h"
#include "sizes.h"


void coronavirus()
{
    InitWindow(screenWidth, screenHeight, "Coronavirus");

    Camera camera = { 0 };
    camera.position = Vector3{ 6.0f, 7.0f, 6.0f };
    camera.target = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model model = LoadModel("resources/models/coronavirusFiles/coronavirus.obj");
    Texture2D texture = LoadTexture("resources/models/coronavirusFiles/coronavirus.mtl");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;


    Vector3 position = { 0.0f, 0.0f, 0.0f };



    char name[] = "Ebola virus";
    char symptomps[] = "Symptoms:";
    char infoSymptomps[] = "Fever; Aches and pains, such as severe\nheadacheand muscleand joint pain;\nWeaknessand fatigue; Sore throat.";
    char cures[] = "Cures:";
    char infoCures[] = "There's no cure for Ebola, though\nresearchers are working on it. There\nare two drug treatments which have\nbeen approved for treating Ebola.\nInmazeb is a mixture of three\nmonoclonal antibodies (atoltivimab,\n maftivimab, and odesivimab-ebgn).";
    char dangers[] = "Dangers:";
    char infoDangers[] = "Without prompt and appropriate\ntreatment as many as 90% of people\nwho become sick with Ebola\nvirus disease die.";



    Rectangle rect = { screenWidth - screenWidth / 4 - 150,0,screenWidth / 4 + 150, screenHeight };
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_ORBITAL);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        DrawModel(model, position, 1.0f, WHITE);

        DrawGrid(10, 1.0f);
        EndMode3D();
        DrawRectangleRec(rect, BLACK);
        DrawText(name, rect.x + 30, rect.y + 50, 55, WHITE);
        DrawText(symptomps, rect.x + 30, rect.y + 130, 35, WHITE);
        DrawText(infoSymptomps, rect.x + 30, rect.y + 180, 20, WHITE);
        DrawText(cures, rect.x + 30, rect.y + 280, 35, WHITE);
        DrawText(infoCures, rect.x + 30, rect.y + 330, 20, WHITE);
        DrawText(dangers, rect.x + 30, rect.y + 550, 35, WHITE);
        DrawText(infoDangers, rect.x + 30, rect.y + 600, 20, WHITE);

        EndDrawing();
    }

    UnloadModel(model);
    UnloadTexture(texture);
    CloseWindow();
}