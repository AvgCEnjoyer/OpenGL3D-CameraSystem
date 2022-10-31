#include "Mesh.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <fstream>

Mesh::Mesh() {

	std::vector<glm::vec3> meshData;

}


Mesh::Mesh(std::string file) {

	std::vector<glm::vec3> meshData;
	getMeshData(file);
}


std::vector<glm::vec3> Mesh::getMeshData(std::string filePath) {

	std::vector<int> faces;

	std::string content;
	std::vector<std::string> lines;

	std::ifstream fileStream(filePath, std::ios::in);


	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
	}

	while (!fileStream.eof()) {
		std::getline(fileStream, content);
		lines.push_back(content);
	}
	fileStream.close();

	float x, y, z;

	for (std::string& content : lines) {
		if (content[0] == 'v') {
			if (content[1] == ' ') {
				sscanf_s(content.c_str(), "v %f %f %f", &x, &y, &z);
				meshData.push_back(glm::vec3(x, y, z));
			}
		}
		if (content[0] == 'f') {
			if (content[1] == ' ') {
				sscanf_s(content.c_str(), "f %f %f %f", &x, &y, &z);
				faces.push_back((int) x);
				faces.push_back((int) y);
				faces.push_back((int) z);
			}
		}
	}

	std::vector<glm::vec3> finalMesh;

	for (int i = 0; i < faces.size(); i++) {

		finalMesh.push_back(meshData.at(faces.at(i) - 1));
	}

	meshData.clear();

	for (int i = 0; i < finalMesh.size(); i++) meshData.push_back(finalMesh.at(i));

	return meshData;
}