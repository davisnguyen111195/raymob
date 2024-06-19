//
// Created by datnt on 6/19/2024.
//

#ifndef RAYMOB_SNAKE_HPP
#define RAYMOB_SNAKE_HPP

#include "raylib.h"
#include <raymath.h>
#include "Game.hpp"
#include <deque>
class Snake{
public:
//    int m_cellSize;
//    int m_cellCount;
//    Color m_color;
    std::deque<Vector2> m_body;
    Vector2 m_direction = {1, 0};
    Snake();

    void Draw();
    void Update();
};
#endif //RAYMOB_SNAKE_HPP
