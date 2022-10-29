#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


class GLBuffer {

public:
	GLBuffer(int n);
	GLBuffer();
	virtual ~GLBuffer() = default;

	unsigned int bufferID;
	unsigned int freeSpace;

	unsigned int getBuffer();
	unsigned int getNextSpace();
	void push();
	void pop();
	void pushData(glm::vec3 data);

};