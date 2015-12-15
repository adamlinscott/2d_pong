#include "OrthoCamera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> //https://open.gl/transformations

OrthoCamera::OrthoCamera(GLSLProgram* glslProgram, glm::vec3 position, glm::vec2 size)
                :
                Camera::Camera(glslProgram, position),
                size(size)
{

}

void OrthoCamera::activate()
{
    SDL_LogMessage(SDL_LOG_CATEGORY_RENDER, SDL_LOG_PRIORITY_DEBUG, "  orthoCamera activated");

	float FoV = 900;

    //set projectionMatrix - how we go from 3D to 2D
    glm::vec2 halfSize = size / 2.0f;
	glm::mat4 projectionMatrix = glm::perspective(FoV, 1.0f, 0.1f, 1000.0f);
    glUniformMatrix4fv(glslProgram->projectionMatrixLocation, 1, false, glm::value_ptr(projectionMatrix));

    //set viewMatrix - how we control the view (viewpoint, view direction, etc)
    glm::mat4 viewMatrix = glm::lookAt(glm::vec3(position.x, position.y - 30, 150.0f), glm::vec3(position.x, position.y + 30, -110.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glslProgram->viewMatrixLocation, 1, false, glm::value_ptr(viewMatrix));
};
