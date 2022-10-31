#pragma once
#include <iostream>
#include <vector>
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"


class Mesh {

public:
	Mesh(std::string file);
	Mesh();
	virtual ~Mesh() = default;

	std::vector<glm::vec3> meshData;

	std::vector<glm::vec3> getMeshData(std::string filePath);

};