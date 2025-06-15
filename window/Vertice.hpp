#pragma once

class Vertice {
    public:
        float x;
        float y;
        static int windowWidth;
        static int windowHeight;
        Vertice(float x, float y) : x(this->mapToRangeX(x, windowWidth)), y(this->mapToRangeY(y, windowHeight)) {  }
        Vertice() {  }

    private: 
        float mapToRangeX(float xOriginal, int sizeMax) {
            return -1.0f + ((xOriginal - 0.0f) / (sizeMax - 0.0f)) * 2.0f;
        }
        float mapToRangeY(float xOriginal, int sizeMax) {
            return 1.0f - ((xOriginal - 0.0f) / (sizeMax - 0.0f)) * 2.0f;
        }
};