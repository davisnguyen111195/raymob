//
// Created by datnt on 6/19/2024.
//
#include "../headers/Snake.hpp"

Snake::Snake(){
    m_body = {
            Vector2{6, 9},
            Vector2{5, 9},
            Vector2{4, 9}
    };
}

void Snake::Draw() {
    for(int i = 0; i < m_body.size(); i++){
        float x = m_body[i].x;
        float y = m_body[i].y;
        auto segment = Rectangle{x * (float)cellSize,
                                 y * (float)cellSize,
                                 (float)cellSize,
                                 (float)cellSize};

        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
}

void Snake::Update() {
    m_body.pop_back();
    m_body.push_front(Vector2Add(m_body[0], m_direction));
}