#pragma once
#include "Sandbox.h"
#include "GLBuffer.h"
#include "Triangle.h"
#include "Shader.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glfw/glfw3.h>

class GameApp {

public:

	GameApp();
	virtual ~GameApp() = default;

	Cam3d camera;

	GLBuffer buf;
	GLBuffer* buffer;

	std::string vShader;
	std::string fShader;

	glm::mat4 Projection;
	glm::vec3 camPosition;
	glm::mat4 viewMatrix;

	

	void setupProgram();

	void initProgram(int id);

	void update(GLFWwindow& window);

	void program_id0();
	void program_id1();
};