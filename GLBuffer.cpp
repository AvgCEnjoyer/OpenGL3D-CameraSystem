#include "GLBuffer.h"
#include <iostream>

GLBuffer::GLBuffer() {

	bufferID = 0;
	freeSpace = 0;
}

GLBuffer::GLBuffer(int n) {

	freeSpace = 1;
	bufferID;

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, n * sizeof(float), NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
}

unsigned int GLBuffer::getBuffer() { return bufferID; }

unsigned int GLBuffer::getNextSpace() { return freeSpace; }

void GLBuffer::push() { freeSpace++; }

void GLBuffer::pop() { freeSpace--; }

void GLBuffer::pushData(glm::vec3 data) {
	
	int targetPos = (freeSpace - 1) * 3;

	float vertices[3];

	vertices[0] = data.x;
	vertices[1] = data.y;
	vertices[2] = data.z;

	glBufferSubData(GL_ARRAY_BUFFER, (freeSpace-1) * 3 * sizeof(float), 3 * sizeof(float), vertices);

	push();
}