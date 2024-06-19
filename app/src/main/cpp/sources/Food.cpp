//
// Created by davidng on 6/18/24.
//
#include "../headers/Food.hpp"

Food::Food(){
    Image image = LoadImage("food.png");
    m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
    m_position = GenerateRandomPos();
}

Food::~Food(){
    UnloadTexture(m_texture);
}
void Food::Draw() {
    DrawTexture(m_texture,
                m_position.x * cellSize,
                m_position.y * cellSize,
                WHITE);

}

Vector2 Food::GenerateRandomPos() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}