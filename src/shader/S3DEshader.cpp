//
// Created by VectorE on 10.03.2023.
//

#include "S3DEshader.h"

namespace S3DE {
    S3DEshader::S3DEshader(const GLchar *vPath, const GLchar *fPath) {
        GLuint vertex = createShader(vPath, 0);
        GLuint fragment = createShader(fPath, 1);

        this->Program = buildProgram(vertex, fragment);

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        std::cout << "Shader Program created\n";
    }

    void S3DEshader::Use() {
        glUseProgram(this->Program);
    }

    GLuint S3DEshader::createShader(const GLchar *shaderPath, int type) {

        std::string shaderSource;
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::badbit);

        try {
            shaderFile.open(shaderPath);
            std::stringstream shaderStream;
            shaderStream << shaderFile.rdbuf();
            shaderFile.close();
            shaderSource = shaderStream.str();
        } catch(std::ifstream::failure e) {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        const GLchar* shaderCode = shaderSource.c_str();

        GLuint shader;
        GLint success;
        GLchar infoLog[512];

        switch(type) {
            case 0:
                shader = glCreateShader(GL_VERTEX_SHADER);
                break;
            case 1:
                shader = glCreateShader(GL_FRAGMENT_SHADER);
                break;
            default:
                std::cout << "ERROR::SHADER::TYPE=" << type <<"::COMPILATION_FAILED\n" << infoLog << std::endl;
                return NULL;
        }
        glShaderSource(shader, 1, &shaderCode, NULL);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::TYPE=" << type <<"::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        return shader;
    }

    GLuint S3DEshader::buildProgram(GLuint vertex, GLuint fragment) {
        GLuint program = glCreateProgram();

        GLint success;
        GLchar infoLog[512];

        glAttachShader(program, vertex);
        glAttachShader(program, fragment);
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        return program;
    }
}
