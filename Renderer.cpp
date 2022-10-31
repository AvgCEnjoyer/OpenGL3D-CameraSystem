#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Renderer.h"
#include "Shader.h"
#include "Triangle.h"
#include "GLBuffer.h"
#include "Sandbox.h"
#include <iostream>

Renderer::Renderer() {}

void Renderer::render(GLFWwindow& window) {

    glViewport(0, 0, 1920, 1080);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    double lasttime = glfwGetTime();

    GameApp game = GameApp();
    game.initProgram(1);

    glfwSetInputMode(&window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(&window, mouseCallback);

    while (!glfwWindowShouldClose(&window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, game.buffer->freeSpace);

        game.update(window);

        glfwSwapBuffers(&window);
        glfwPollEvents();

        while (glfwGetTime() < lasttime + 1.0 / 144) {}
        lasttime += 1.0 / 144;
    }
}