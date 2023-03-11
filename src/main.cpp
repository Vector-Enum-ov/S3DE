//
// Created by VectorE on 01.03.2023.
//

#include <iostream>
#include <conio.h>

#define GLEW_STATIC
#include "./../include/glew.h"
#include "./../include/glfw3.h"

#include "./../lib/glm/glm.hpp"
#include "./../lib/glm/gtc/matrix_transform.hpp"
#include "./../lib/glm/gtc/type_ptr.hpp"

#include "./shader/S3DEshader.h"

using S3DE::S3DEshader;

int initEnvironment();

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void switchFillPolygon();

bool fillPolygon = true;

GLFWwindow* win;

int main(void) {
    initEnvironment();

    S3DEshader shd = S3DEshader("./../res/default.vertex", "./../res/default.fragment");

    GLfloat vertices[] = {
            // Positions                       // Colors
            0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
            -0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Left
            0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f   // Top
    };
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    while(!glfwWindowShouldClose(win))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shd.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(win);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    std::cout << "GLFW TERMINATED\n";
    getch();
    return 0;
}

int initEnvironment() {
    if (!glfwInit()) {
        std::cout << "GLFW ERROR OCCURRED\n";
        exit(-1);
    }
    std::cout << "GLFW INITIATED\n";
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    win = glfwCreateWindow(800, 600, "title", nullptr, nullptr);

    if (win == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-2);
    }
    std::cout << "WINDOW CREATED\n";
    glfwMakeContextCurrent(win);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(-3);
    }
    std::cout << "GLEW INITIATED\n";

    glfwSetKeyCallback(win, key_callback);

    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        switchFillPolygon();
}

void switchFillPolygon() {
    if (fillPolygon)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    fillPolygon = !fillPolygon;
}