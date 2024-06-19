/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press Shift+F10 for Android Studio.
*
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5) and reviewed by Victor Le Juez
*
********************************************************************************************/

 // This header can replace 'raylib.h' and includes additional functions related to Android.



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
#include "raymob.h"
#include "../headers/logging.h"
#include "../headers/Food.hpp"
#include "../headers/Snake.hpp"

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};
int cellSize = 30;
int cellCount = 25;


int main() {

    LOGD("Start game");
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
//    int screen_width = GetScreenWidth();
//    int screen_height = GetScreenHeight();
//    LOGD("Width = %d", screen_width);
//    LOGD("Height = %d", screen_height);
    SetTargetFPS(60);
    Food fo = Food(cellSize, cellCount, darkGreen);
    Snake snake = Snake(cellSize, cellCount, darkGreen);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(green);
        fo.Draw();
        snake.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}