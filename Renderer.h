#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"

class Renderer {

public:
	Renderer();
	virtual ~Renderer() = default;

	void render(GLFWwindow& window);

};