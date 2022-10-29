#include "Sandbox.h"
#include "GLBuffer.h"
#include "Triangle.h"
#include "Shader.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glfw/glfw3.h>


GameApp::GameApp() {

    camera = Cam3d();

    Projection = glm::perspective(glm::radians(90.0f), (float)1920 / (float)1080, 0.1f, 100.0f);
    camPosition = camera.camPosition;
    viewMatrix = Projection * camera.view;


}

void GameApp::setupProgram() {}


void GameApp::initProgram(int id) {

	
    if (id == 0) program_id0();
    else if (id == 1) program_id1();
	
}

void GameApp::update(GLFWwindow& window) {

    camera.run(window);
    viewMatrix = Projection * camera.view;

    glUniformMatrix4fv(0, 1, GL_FALSE, &viewMatrix[0][0]);
}


void GameApp::program_id0() {

    buf = GLBuffer(3750000);
    buffer = &buf;

    for (float i = 0; i < 100.0f; i++) {
        for (float j = 0; j < 100.0f; j++) {
            for (float k = 0; k < 100.0f; k++) {
                Triangle t = Triangle(glm::vec3(0.0f + k * 3.0f - 50.0f, 0.0f + i * 3.0f - 25.0f, 0.0f - j * 3.0f),
                    glm::vec3(1.0f + k * 3.0f - 50.0f, 1.0f + i * 3.0f - 25.0f, 0.0f - j * 3.0f),
                    glm::vec3(2.0f + k * 3.0f - 50.0f, 0.0f + i * 3.0f - 25.0f, 0.0f - j * 3.0f));
                t.bind(*buffer);
            }
        }
    }

    vShader = getFileShader("VertexShader.vert");
    fShader = getFileShader("FragmentShader.frag");

    unsigned int shader = createShader(vShader, fShader);
    glUseProgram(shader);

    glGetUniformLocation(shader, "MVP");
    glUniformMatrix4fv(shader, 1, GL_FALSE, &viewMatrix[0][0]);

   

}

void GameApp::program_id1() {

    buf = GLBuffer(1000);
    buffer = &buf;

    Triangle t = Triangle(glm::vec3(-0.5f, 0.0f, 0.0f), 
                          glm::vec3(0.5f, 0.0f, 0.0f), 
                          glm::vec3(0.0f, 1.0f, 0.0f));
    t.bind(*buffer);

    vShader = getFileShader("VertexShader.vert");
    fShader = getFileShader("FragmentShader.frag");

    unsigned int shader = createShader(vShader, fShader);
    glUseProgram(shader);

    glGetUniformLocation(shader, "MVP");
    glUniformMatrix4fv(shader, 1, GL_FALSE, &viewMatrix[0][0]);
}