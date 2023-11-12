#pragma once

#include "raylib.h"

#define NUMBER_TEST_AND_BACK 2
void playMenu();

typedef enum {
    BACKPLAY,
    TESTPLAY
}backPlayButton;

static const char* backPlayText[] = {
    "Back",
    "Test"
};

const int screenWidth = 1250;
const int screenHeight = 800;