//
// Created by VectorE on 10.03.2023.
//

#ifndef S3DE_S3DESHADER_H
#define S3DE_S3DESHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLEW_STATIC
#include "./../../include/glew.h"

namespace S3DE {
    class S3DEshader {
    public:
        S3DEshader(const GLchar* vPath, const GLchar* fPath);
        void Use();
    private:
        GLuint Program;
        GLuint createShader(const GLchar *shaderPath, int type);
        GLuint buildProgram(GLuint vertex, GLuint fragment);
    };
}

#endif //S3DE_S3DESHADER_H
