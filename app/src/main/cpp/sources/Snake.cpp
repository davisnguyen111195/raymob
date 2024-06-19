//
// Created by datnt on 6/19/2024.
//
#include "../headers/Snake.hpp"

Snake::Snake(int cellSize, int cellCount, Color color) : m_cellSize(cellSize),
                                                         m_cellCount(cellCount),
                                                         m_color(color){
    m_body = {
            Vector2{6, 9},
            Vector2{5, 9},
            Vector2{4, 9}
    };
}

void Snake::Draw() {
    for(int i = 0; i < (int)m_body.size(); i++){
        float x = m_body[i].x;
        float y = m_body[i].y;
        Rectangle segment = Rectangle{x * m_cellSize,
                                      y * m_cellSize,
                                      (float)m_cellSize,
                                      (float)m_cellSize};

        DrawRectangleRounded(segment, 0.5, 6, m_color);
    }

}