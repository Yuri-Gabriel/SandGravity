#pragma once

#include "Vertice.hpp"

class Cube {
    public:
        Vertice vertices[4];
        int xPos;
        int yPos;
        int width;
        int height;
        float red;
        float green;
        float blue;

        Cube(
            int xPos,
            int yPos,
            int width,
            int height
        ): xPos(xPos), yPos(yPos), width(width), height(height) { this->setVertices(); }

        void setVertices() {
            this->vertices[0] = Vertice(xPos, yPos);//top_left_pos;
            this->vertices[1] = Vertice(xPos + width, yPos);//top_right_pos;
            this->vertices[2] = Vertice(xPos, yPos + height);//botton_left_pos;
            this->vertices[3] = Vertice(xPos + width, yPos + height);//botton_right_pos;
        }

        void setColor(float red, float green, float blue) {
            this->red = red;
            this->green = green;
            this->blue = blue;
        }

        void updatePosition(int new_x, int new_y) {
            this->xPos = new_x;
            this->yPos = new_y;

            this->vertices[0] = Vertice(new_x, new_y);//top_left_pos;
            this->vertices[1] = Vertice(new_x + this->width, new_y);//top_right_pos;
            this->vertices[2] = Vertice(new_x, new_y + this->height);//botton_left_pos;
            this->vertices[3] = Vertice(new_x + this->width, new_y + this->height);//botton_right_pos;
        }
};