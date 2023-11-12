#pragma once

#include "raylib.h"

#define NUMBER_TEST_AND_BACK 1
void playMenu();

typedef enum {
    BACKPLAY
}backPlayButton;

static const char* backPlayText[] = {
    "Back"
};

const int screenWidth = 1250;
const int screenHeight = 800;