#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <glfw/glfw3.h>

float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 0;
float lastY = 0;

bool firstMouse = false;

glm::vec3 ncamTarget = glm::vec3(0.0f, 0.0f, -1.0f);


Cam3d::Cam3d() {

	camPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	camTarget = ncamTarget;
	camDirection = glm::normalize(camPosition - camTarget); //Richtung : [Origo -> Camera]

	up = glm::vec3(0.0f, 1.0f, 0.0f);
	camRight = glm::normalize(glm::cross(up, camDirection)); //Kreuzprodukt VektorNachOben x KameraRichtung gibt die Richtung der positiven x-Achse als Ergebnis 
	camUp = glm::cross(camDirection, camRight);

	view = glm::lookAt(camPosition, camTarget, camUp);

}

void Cam3d::run(GLFWwindow& window) {

	if (glfwGetKey(&window, GLFW_KEY_A) == GLFW_PRESS) {
		camPosition -= glm::normalize(glm::cross(camTarget, camUp)) * 0.05f;
	}
	if (glfwGetKey(&window, GLFW_KEY_D) == GLFW_PRESS) {
		camPosition += glm::normalize(glm::cross(camTarget, camUp)) * 0.05f;
	}
	if (glfwGetKey(&window, GLFW_KEY_W) == GLFW_PRESS) {
		camPosition += 0.05f * camTarget;
	}
	if (glfwGetKey(&window, GLFW_KEY_S) == GLFW_PRESS) {
		camPosition -= 0.05f * camTarget;
	}

	camTarget = glm::normalize(ncamTarget);
	camUp = glm::cross(camDirection, camRight);
	view = glm::lookAt(camPosition, camPosition + camTarget, camUp);
}

//Muss zwingend eine außerhalb von jeglichen Klassen definierte Funktion sein, um per glfw Aufruf darauf zu zeigen*
void mouseCallback(GLFWwindow* window, double xpos, double ypos) {

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	ncamTarget = glm::normalize(direction);
}

