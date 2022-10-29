#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

#include <GLFW/glfw3.h>

unsigned int compileShader(unsigned int type, const std::string& source);
unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);

std::string getFileShader(std::string filePath);
