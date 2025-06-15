#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "LinkedList.hpp"
#include "Cube.hpp"
#include "Vertice.hpp"

using namespace std;

int Vertice::windowWidth = 0;
int Vertice::windowHeight = 0;

class Window {
public:
    
    Window(int width, int height, string title) {
        this->width = width;
        this->height = height;
        this->title = title;
        Vertice::windowWidth = width;
        Vertice::windowHeight = height;
        this->cubeSize = 10;
        this->red = 1.0f;
        this->green = 0.0f;
        this->blue = 0.0f;
    }

    void start() {
        if (!glfwInit()) {
            cerr << "Erro ao inicializar a GLFW." << endl;
            return;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        GLFWwindow* window = glfwCreateWindow(
            this->width, this->height, this->title.c_str(), NULL, NULL
        );

        glfwMakeContextCurrent(window);
        glfwSetCursorPosCallback(window, cursor_position_callback);
        this->initOpenGL();
        

        while (!glfwWindowShouldClose(window)) {
            glfwSwapBuffers(window);
            glfwPollEvents();

            this->mouse_button_pressed_callback(window);
            this->drawCubes(); 
            this->gravity();
        }

        glfwDestroyWindow(window);
        glfwTerminate();
    }
private:
    int width;
    int height;
    int cubeSize;
    inline static int x_cursor = 0.0;
    inline static int y_cursor = 0.0;
    string title;
    inline static LinkedList<Cube> cubes;
    float red;
    float green;
    float blue;

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
        x_cursor = (int) xpos;
        y_cursor = (int) ypos;
        
    }

    void mouse_button_pressed_callback(GLFWwindow* window) {
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            int xGrid = static_cast<int>(x_cursor) / this->cubeSize;
            int alignedX = xGrid * this->cubeSize;

            int yGrid = static_cast<int>(y_cursor) / this->cubeSize;
            int alignedY = yGrid * this->cubeSize;

            Cube cube(alignedX, alignedY, this->cubeSize, this->cubeSize);
            cube.setColor(this->red, this->green, this->blue);

            this->cubes.add(cube);
            this->updateCubeColor();
        }
    }

    void initOpenGL() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void drawCubes() {
        // desenhar todos os cubos da lista
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_TRIANGLES);

        this->cubes.forEach([](Cube cube) {
            glColor3f(cube.red, cube.green, cube.blue);
            glVertex2f(cube.vertices[0].x, cube.vertices[0].y);
            glVertex2f(cube.vertices[2].x, cube.vertices[2].y);
            glVertex2f(cube.vertices[1].x, cube.vertices[1].y);

            glVertex2f(cube.vertices[2].x, cube.vertices[2].y);
            glVertex2f(cube.vertices[3].x, cube.vertices[3].y);
            glVertex2f(cube.vertices[1].x, cube.vertices[1].y);
        });

        glEnd();
    }

    void gravity() {
        int windowHeight = this->height;
        int cSize = this->cubeSize;
        this->cubes.forEach([&windowHeight, &cSize](Cube& cube) {
            if (cube.yPos + cube.height >= windowHeight) return;

            if (haveCubeBelow(cube)) return;

            cube.updatePosition(cube.xPos, cube.yPos + cSize);
            
        });
    }

    static bool haveCubeBelow(const Cube& currentCube) {
        bool have = false;
        cubes.forEachBreakable([&currentCube, &have](Cube& otherCube) -> bool {
            if (&otherCube == &currentCube) return false;

            if (otherCube.xPos == currentCube.xPos &&
                otherCube.yPos == currentCube.yPos + currentCube.height) {
                have = true;
                return true; 
            }
            return false;
        });
        return have;
    }

    void updateCubeColor() {
        if(this->green < 1.0f) {
            this->green += 0.1f;
            return;
        }
        if(this->blue < 1.0f) {
            this->blue += 0.1f;
            return;
        }
        this->green = 0.0f;
        this->blue = 0.0f;
    }
};