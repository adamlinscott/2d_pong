#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "GLSLProgram.hpp"
#include "Vertex.hpp"

class Mesh {
public:

    GLSLProgram* glslProgram = nullptr;

    Mesh(GLSLProgram* glslProgram, std::vector<Vertex> vertexData);

    void draw(GLenum mode = GL_TRIANGLES);
    void bufferData(std::vector<Vertex> newVertexData = {});
    std::vector<Vertex> vertexData;

private:
    GLuint vertexDataBufferObject = 0;
    GLuint vertexArrayObject = 0;
    void setupVertexArrayObject();
};
