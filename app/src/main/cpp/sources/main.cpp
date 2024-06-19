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
#include "raylib.h"
#include "../headers/logging.h"
#include "../headers/Food.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Game.hpp"
#include <deque>


double lastUpdateTime = 0;

bool eventTrigger(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {

    LOGD("Start game");
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");

    SetTargetFPS(60);
    Food food = Food();
    Snake snake = Snake();
    Vector2 touchPosition = {0, 0};
    Rectangle touchArea = {0, 0, 4000, 3000};

    int currentGesture = GESTURE_NONE;
    int lastGesture = GESTURE_NONE;

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawRectangleLines(0, 0, cellSize * cellCount, cellSize * cellCount, WHITE);
        if (eventTrigger(0.3)) {
            snake.Update();
        }

        //swipe
        lastGesture = currentGesture;
        currentGesture = GetGestureDetected();
        touchPosition = GetTouchPosition(0);

        if (CheckCollisionPointRec(touchPosition, touchArea) && (currentGesture != GESTURE_NONE)) {
            if (currentGesture != lastGesture) {
                switch (currentGesture) {
                    case GESTURE_SWIPE_UP:
                        if(snake.m_direction.y != 1){
                            snake.m_direction = {0, -1};
                        }
                        LOGD("SWIPE_UP");
                        break;
                    case GESTURE_SWIPE_DOWN:
                        if(snake.m_direction.y != -1){
                            snake.m_direction = {0, 1};
                        }
                        LOGD("SWIPE_DOWN");
                        break;
                    case GESTURE_SWIPE_LEFT:
                        if(snake.m_direction.x != 1){
                            snake.m_direction = {-1, 0};
                        }
                        LOGD("SWIPE_LEFT");
                        break;
                    case GESTURE_SWIPE_RIGHT:
                        if(snake.m_direction.x != -1){
                            snake.m_direction = {1, 0};
                        }
                        LOGD("SWIPE_RIGHT");
                        break;
                    default:
                        break;
                }
            }
        }

        ClearBackground(green);
        food.Draw();
        snake.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}