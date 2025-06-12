#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "LinkedList.hpp"
#include "Cube.hpp"

using namespace std;

class Window {
public:
    Window(int width, int height, string title) {
        this->width = width;
        this->height = height;
        this->title = title;
    }

    void start() {

        if (!glfwInit()) {
            cerr << "Erro ao inicializar a GLFW." << endl;
            return;
        }

        GLFWwindow* window = glfwCreateWindow(
            this->width, this->height, this->title.c_str(), NULL, NULL
        );
        this->cubes.add(Cube(
            Vertice(-0.05f, 0.05f),
            Vertice(0.05f, 0.05f),
            Vertice(-0.05f, -0.05f),
            Vertice(0.05f, -0.05f)
        ));

        glfwMakeContextCurrent(window);
        glfwSetCursorPosCallback(window, cursor_position_callback);
        this->initOpenGL();
        

        while (!glfwWindowShouldClose(window)) {
            glfwSwapBuffers(window);
            glfwPollEvents();

            this->mouse_button_pressed_callback(window);
            this->render();
        }

        glfwDestroyWindow(window);
        glfwTerminate();
    }
private:
    int width;
    int height;
    inline static double x_cursor = 0.0;
    inline static double y_cursor = 0.0;
    string title;
    LinkedList<Cube> cubes;

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
        x_cursor = xpos;
        y_cursor = ypos;
        
    }

    void mouse_button_pressed_callback(GLFWwindow* window) {
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            // adiciona um cubo na lista
            printf("x: %.2f\ny: %.2f\n", x_cursor, y_cursor);
        }
    }

    void initOpenGL() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void render() {
        // desenhar todos os cubos da lista
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);

        this->cubes.forEach([](Cube cube) {
            glVertex2f(cube.vertices[0].x, cube.vertices[0].y);
            glVertex2f(cube.vertices[2].x, cube.vertices[2].y);
            glVertex2f(cube.vertices[1].x, cube.vertices[1].y);

            glVertex2f(cube.vertices[2].x, cube.vertices[2].y);
            glVertex2f(cube.vertices[3].x, cube.vertices[3].y);
            glVertex2f(cube.vertices[1].x, cube.vertices[1].y);
        });

        glEnd();
        
            

            
        
    }
};