#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glfw/glfw3.h>
#include "Camera.h"
#include "Shader.h"
#include "Renderer.h"


int main() {

    GLFWwindow* window;

    if (!glfwInit())
        return -1;
    
    window = glfwCreateWindow(1920, 1080, "fuk u", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    Renderer rRenderer = Renderer();
    rRenderer.render(*window);


    glfwTerminate();

    return 0;
}