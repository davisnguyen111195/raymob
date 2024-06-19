//
// Created by davidng on 6/18/24.
//

#ifndef RAYMOB_FOOD_HPP
#define RAYMOB_FOOD_HPP
#include "../deps/raymob/raymob.h"
#include "../deps/raylib/raylib.h"
#include "Game.hpp"
class Food{
public:
    Vector2 m_position;
    Texture2D m_texture;
//    int m_cellSize;
//    int m_cellCount;
//    Color m_color;

    Food();
    ~Food();
    void Draw();
    Vector2 GenerateRandomPos();
};
#endif //RAYMOB_FOOD_HPP
