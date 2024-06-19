//
// Created by datnt on 6/19/2024.
//

#ifndef RAYMOB_SNAKE_HPP
#define RAYMOB_SNAKE_HPP
#include <deque>
#include "raylib.h"

class Snake{
public:
    Snake(int cellSize, int cellCount, Color color);
    int m_cellSize;
    int m_cellCount;
    Color m_color;
    std::deque<Vector2> m_body;
    void Draw();
};
#endif //RAYMOB_SNAKE_HPP
