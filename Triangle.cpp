#include "Triangle.h"

Triangle::Triangle(glm::vec3 vVertice1, glm::vec3 vVertice2, glm::vec3 vVertice3) {

	vertice1 = vVertice1;
	vertice2 = vVertice2;
	vertice3 = vVertice3;
}

unsigned int Triangle::bind(GLBuffer& buffer) {

	unsigned int bufferPosID = buffer.getNextSpace();

	buffer.pushData(vertice1);
	buffer.pushData(vertice2);
	buffer.pushData(vertice3);

	return bufferPosID;
}


