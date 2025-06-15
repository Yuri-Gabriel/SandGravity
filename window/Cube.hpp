#pragma once

#include "Vertice.hpp"

class Cube {
    public:
        Vertice vertices[4];

        Cube(
            int xPos,
            int yPos,
            int width,
            int height
        ) {
            this->vertices[0] = Vertice(xPos, yPos);//top_left_pos;
            this->vertices[1] = Vertice(xPos + width, yPos);//top_right_pos;
            this->vertices[2] = Vertice(xPos, yPos + height);//botton_left_pos;
            this->vertices[3] = Vertice(xPos + width, yPos + height);//botton_right_pos;
        }
};