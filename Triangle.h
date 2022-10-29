#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "GLBuffer.h"


class Triangle {

public:
	Triangle(glm::vec3 vVertice1, glm::vec3 vVertice2, glm::vec3 vVertice3);
	virtual ~Triangle() = default;

	glm::vec3 vertice1;
	glm::vec3 vertice2;
	glm::vec3 vertice3;

	unsigned int bind(GLBuffer& buffer);
};