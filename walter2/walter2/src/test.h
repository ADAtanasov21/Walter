#pragma once
#include "sizes.h"
#include "raylib.h"
#include "score.h"

#define NUMBER_QUESTIONS  3

struct Question {
    const char* question;
    const char* answers[4];
    int correctAnswer;
};

Question triviaQuestions[NUMBER_QUESTIONS] = {
    {"Corona?", {"Beer", "Virus", "on king's head", "Rome"}, 2},
    {"ebola", {"yes", "no", "maybe", "nahh"}, 0},
    {"Trembolon", {"da", "ne", "mh", "haide"}, 1}
};
void CheckAnswer(int selectedOption, int& currentQuestion, int& score)
{
    if (selectedOption == triviaQuestions[currentQuestion].correctAnswer)
    {
        score++;
    }

    currentQuestion++;

    if (currentQuestion > NUMBER_QUESTIONS)
    {
        void score();
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

        DrawText(triviaQuestions[currentQuestion].question, 100, 150, 45, RED);
        for (int i = 0; i < 4; i++)
        {
            DrawText(TextFormat("%d. %s", i + 1, triviaQuestions[currentQuestion].answers[i]), 100, 80 + i * 40 +130, 35, GREEN);
        }

        DrawText(TextFormat("Score: %d", score), screenWidth /2-140 , 20, 70, YELLOW);

        EndDrawing();
    }

    CloseWindow();
}