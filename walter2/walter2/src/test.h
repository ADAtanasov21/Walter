#pragma once
#include "sizes.h"
#include "raylib.h"


#define NUMBER_QUESTIONS  5

struct Question {
    const char* question;
    const char* answers[4];
    int correctAnswer;
};

Question triviaQuestions[NUMBER_QUESTIONS] = {
    {"Continue the word Corona...?", {"Beer", "Virus", "on king's head", "on princes's head"}, 1},
    {"What to do when you are sick of flu?", {"Rest", "There's no cure for Flu.", "Take cold showers", "Sleep on opend window."}, 0},
    {"Which virus does not have a tretment?", {"Coronavirus", "Flu", "Esherichia Coli", "Ebola"}, 3},
    {"Is high temperature common symptom for Ebola?", {"Yes", "No", "No, it's common for flu.", "There is no correct question."}, 2},
    {"For which virus is cough a common symptom?", {"Ebola", "Coronavirus", "Esherichia Coli", "Norovirus"}, 1}
};
void CheckAnswer(int selectedOption, int& currentQuestion, int& score)
{
    if (selectedOption == triviaQuestions[currentQuestion].correctAnswer)
    {
        score++;
    }

    currentQuestion++;

    if (currentQuestion >= NUMBER_QUESTIONS)
    {
        int isColideBackPlay = -1;
        bool backPlayTextureReload = false;
        int currentProcesBackTest = 0;

        float recWidth = 95.0f;
        float recHeight = 52.0f;

        Rectangle recBackAndTest[NUMBER_TEST_AND_BACK] = { 0 };
        for (int i = 0; i < NUMBER_TEST_AND_BACK; i++) {
            recBackAndTest[i] = Rectangle{ screenWidth/2 - recWidth +50, screenHeight/2 - recHeight+50 ,recWidth, recHeight };
        }

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
                    
                }
            }
            BeginDrawing();

            ClearBackground(Color{ 0,4,35,255 });

            DrawText(TextFormat("Your score is: %d", score), screenWidth/2-220, screenHeight /2-100, 60, WHITE);

            for (int i = 0; i < NUMBER_TEST_AND_BACK; i++) {
                DrawRectangleRounded(recBackAndTest[i], 5, 1, ((isColideBackPlay == i)) ? Color{ 176,0,24,255 } : Color{ 203,65,84,255 });
                DrawText(backPlayText[i], recBackAndTest[i].x + (recBackAndTest[i].width - MeasureText(backPlayText[i], 20)) / 2, recBackAndTest[i].y + (recBackAndTest[i].height - 20) / 2, 20, WHITE);
            }
            EndDrawing();
        }

        CloseWindow();

    

    }
}
void test()
{
    int currentQuestion = 0;
    int score = 0;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE)) {
            CheckAnswer(0, currentQuestion, score);
        }
        else if (IsKeyPressed(KEY_TWO)) {
            CheckAnswer(1, currentQuestion, score);
        }
        else if (IsKeyPressed(KEY_THREE)) {
            CheckAnswer(2, currentQuestion, score);
        }
        else if (IsKeyPressed(KEY_FOUR)) {
            CheckAnswer(3, currentQuestion, score);
        }

        BeginDrawing();
        ClearBackground(Color{ 0,4,35,255 });

        DrawText(triviaQuestions[currentQuestion].question, 100, 150, 40, RED);
        for (int i = 0; i < 4; i++)
        {
            DrawText(TextFormat("%d. %s", i + 1, triviaQuestions[currentQuestion].answers[i]), 100, 80 + i * 40 +130, 30, GREEN);
        }

        DrawText("Enter a number between 1 to 4!", screenWidth / 2 - 400, 20, 50, YELLOW);

        EndDrawing();
    }

    CloseWindow();
}