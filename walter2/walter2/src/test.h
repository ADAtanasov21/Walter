#pragma once
#include "sizes.h"
#include "raylib.h"

//Number of trivia question
#define NUMBER_QUESTIONS  5

//Structure to represent a trivia question
struct Question {
    const char* question;
    const char* answers[4];
    int correctAnswer;
};

//Array of trivia questions
Question triviaQuestions[NUMBER_QUESTIONS] = {
    {"Continue the word Corona...?", {"Beer", "Virus", "on king's head", "on princes's head"}, 1},
    {"What to do when you are sick of flu?", {"Rest", "There's no cure for Flu.", "Take cold showers", "Sleep on opend window."}, 0},
    {"Which virus does not have a tretment?", {"Coronavirus", "Flu", "Esherichia Coli", "Ebola"}, 3},
    {"Is high temperature common symptom for Ebola?", {"Yes", "No", "No, it's common for flu.", "There is no correct question."}, 2},
    {"For which virus is cough a common symptom?", {"Ebola", "Coronavirus", "Esherichia Coli", "Norovirus"}, 1}
};

//Function that checks the selsected answer and apdate the score
void CheckAnswer(int selectedOption, int& currentQuestion, int& score)
{
    //Check if the selected option is correct
    if (selectedOption == triviaQuestions[currentQuestion].correctAnswer)
    {
        score++;
    }

    //Move to the next question
    currentQuestion++;

    //Check if all questions have been answered
    if (currentQuestion >= NUMBER_QUESTIONS)
    {
        //Variables for handling button interaction
        int isColideBackPlay = -1;
        bool backPlayTextureReload = false;
        int currentProcesBackTest = 0;

        //Set the size of the "Back" button
        float recWidth = 95.0f;
        float recHeight = 52.0f;

        //Array of rectangle for back and test buttons
        Rectangle recBackAndTest[NUMBER_BACK] = { 0 };
        for (int i = 0; i < NUMBER_BACK; i++) {
            recBackAndTest[i] = Rectangle{ screenWidth/2 - recWidth +50, screenHeight/2 - recHeight+50 ,recWidth, recHeight };
        }

        while (!WindowShouldClose())
        {
            //Check collision on back button
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
                    
                }
            }
            BeginDrawing();

            ClearBackground(Color{ 0,4,35,255 });

            //Display the final score
            DrawText(TextFormat("Your score is: %d", score), screenWidth/2-220, screenHeight /2-100, 60, WHITE);

            //Draw a back button
            for (int i = 0; i < NUMBER_BACK; i++) {
                DrawRectangleRounded(recBackAndTest[i], 5, 1, ((isColideBackPlay == i)) ? Color{ 176,0,24,255 } : Color{ 203,65,84,255 });
                DrawText(backPlayText[i], recBackAndTest[i].x + (recBackAndTest[i].width - MeasureText(backPlayText[i], 20)) / 2, recBackAndTest[i].y + (recBackAndTest[i].height - 20) / 2, 20, WHITE);
            }
            EndDrawing();
        }

        CloseWindow();

    

    }
}

//Fubction that starts the trivia test
void test()
{
    int currentQuestion = 0;
    int score = 0;

    while (!WindowShouldClose())
    {
        // Check key persses for answer selection
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

        //Display the current trivia question and answers options
        DrawText(triviaQuestions[currentQuestion].question, 100, 150, 40, RED);
        for (int i = 0; i < 4; i++)
        {
            DrawText(TextFormat("%d. %s", i + 1, triviaQuestions[currentQuestion].answers[i]), 100, 80 + i * 40 +130, 30, GREEN);
        }

        //Display instructions
        DrawText("Enter a number between 1 to 4!", screenWidth / 2 - 400, 20, 50, YELLOW);

        EndDrawing();
    }

    CloseWindow();
}