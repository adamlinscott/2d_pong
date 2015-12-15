#include "Quad.hpp"

const float low = -1.0f;
const float high = 1.0f;

Quad::Quad(GLSLProgram* glslProgram) :
              Mesh::Mesh(glslProgram, std::vector<Vertex> {
	//bottom
    Vertex(	glm::vec3(	low,	high,	0.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 1.0f) ),
    Vertex(	glm::vec3(	low,	low,	0.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
    Vertex(	glm::vec3(	high,	high,	0.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
    Vertex(	glm::vec3(	high,	high,	0.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
    Vertex(	glm::vec3(	low,	low,	0.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
    Vertex(	glm::vec3(	high,	low,	0.0f),	glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),	glm::vec2(1.0f, 0.0f) ),

	//top
	Vertex(	glm::vec3(	low,	high,	5.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	low,	5.0f),	glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	high,	5.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	high,	high,	5.0f),	glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	low,	5.0f),	glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	low,	5.0f),	glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),	glm::vec2(1.0f, 0.0f) ),

	//left
	Vertex(	glm::vec3(	low,	high,	5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	low,	5.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	low,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	low,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	low,	low,	5.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 0.0f) ),
	
	//right
	Vertex(	glm::vec3(	high,	high,	5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 1.0f) ),
	Vertex(	glm::vec3(	high,	low,	5.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	high,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	high,	low,	0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	low,	5.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),	glm::vec2(1.0f, 0.0f) ),

	//back
	Vertex(	glm::vec3(	low,	high,	5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	high,	high,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	high,	5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	high,	5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(1.0f, 0.0f) ),

	//front
	Vertex(	glm::vec3(	low,	low,	5.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	low,	0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	low,	0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	high,	low,	0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),	glm::vec2(1.0f, 1.0f) ),
	Vertex(	glm::vec3(	low,	low,	5.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),	glm::vec2(0.0f, 0.0f) ),
	Vertex(	glm::vec3(	high,	low,	5.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),	glm::vec2(1.0f, 0.0f) ),
	
	})
{}
