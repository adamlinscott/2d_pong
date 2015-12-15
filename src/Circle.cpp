#include "Circle.hpp"
#include <glm/gtc/constants.hpp>

Circle::Circle(GLSLProgram* glslProgram, int segments) :
              Mesh::Mesh(glslProgram),
              segments(segments)
{
    const static float TWO_PI = glm::two_pi<float>();
    GLfloat anglePerSegmentRads = TWO_PI / (float)segments;

	GLfloat x = 0.0;
	GLfloat y = 1.0;

    //top
	Vertex a = Vertex(glm::vec3(x, y, 0.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f));
	Vertex b = Vertex(glm::vec3(x, y, 0.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f));
	Vertex c = Vertex(glm::vec3(x, y, 5.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f));
	Vertex d = Vertex(glm::vec3(x, y, 5.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f));

    for(int i = 1 ; i <= segments ; ++i)
    {
        GLfloat angleRads = anglePerSegmentRads * i;
        x = sin(angleRads);
        y = cos(angleRads);

		b = Vertex(glm::vec3(x, y, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f));
		d = Vertex(glm::vec3(x, y, 5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f));
		
		//edge
		vertexData.push_back(a);
		vertexData.push_back(b);
		vertexData.push_back(c);
		vertexData.push_back(c);
		vertexData.push_back(b);
		vertexData.push_back(d);
		//top
		vertexData.push_back(c);
		vertexData.push_back(Vertex(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 0.5f)));
		vertexData.push_back(d);
		//bottom
		vertexData.push_back(a);
		vertexData.push_back(Vertex(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 0.5f)));
		vertexData.push_back(b);

		a = b;
		c = d;
    }
    bufferData();
}
