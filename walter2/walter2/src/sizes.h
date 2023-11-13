#pragma once
#include "raylib.h"

//Number of buttons for back options
#define NUMBER_BACK 1

//Declaration of the playMenu Function
void playMenu();


//Enumeration to represent back play button
typedef enum {
    BACKPLAY
}backPlayButton;

//Array to store text for back play button
static const char* backPlayText[] = {
    "Back"
};

//The sizes of the window
const int screenWidth = 1250;
const int screenHeight = 800;