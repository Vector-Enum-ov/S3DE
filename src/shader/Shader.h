//
// Created by VectorE on 10.03.2023.
//

#ifndef S3DE_SHADER_H
#define S3DE_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLEW_STATIC
#include "./../../include/glew.h"

class Shader {
public:
    GLuint Program;
    Shader(const GLchar* vPath, const GLchar* fPath);
    void Use();
};


#endif //S3DE_SHADER_H
