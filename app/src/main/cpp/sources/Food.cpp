//
// Created by davidng on 6/18/24.
//
#include "../headers/Food.hpp"

Food::Food(int cellSize, int cellCount, Color color) :
                                            m_cellSize(cellSize),
                                            m_cellCount(cellCount),
                                            m_color(color) {
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
                m_position.x * m_cellSize,
                m_position.y * m_cellSize,
                WHITE);

}

Vector2 Food::GenerateRandomPos() {
    float x = GetRandomValue(0, m_cellCount - 1);
    float y = GetRandomValue(0, m_cellCount - 1);
    return Vector2{x, y};
}