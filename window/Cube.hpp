#pragma once

#include "Vertice.hpp"

class Cube {
    public:
        Vertice vertices[4];

        Cube(
            Vertice top_left_pos,
            Vertice top_right_pos,
            Vertice botton_left_pos,
            Vertice botton_right_pos
        ) {
            this->vertices[0] = top_left_pos;
            this->vertices[1] = top_right_pos;
            this->vertices[2] = botton_left_pos;
            this->vertices[3] = botton_right_pos;
        }
};