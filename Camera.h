#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glfw/glfw3.h>

class Cam3d {

public:
	Cam3d();
	virtual ~Cam3d() = default;

	glm::vec3 camPosition;
	glm::vec3 camDirection;
	glm::vec3 camTarget;

	glm::vec3 up;
	glm::vec3 camRight;

	glm::vec3 camUp;

	glm::mat4 view;


	void run(GLFWwindow& window);
	void mouseCallback(GLFWwindow* window, double xpos, double ypos);

};

#define FUNCTIONS_H_INCLUDED
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

