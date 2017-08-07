#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "display.h"
#include "file_system.h"

float vertices[] = {
  -0.5f, -0.5f, 0.0f,
   0.5f, -0.5f, 0.0f,
   0.0f,  0.5f, 0.0f
};

int main() {
  Display display;

  initDisplay(&display);

  // Create Vertex Buffer Object
  unsigned int VBO;
  glGenBuffers(1, &VBO);

  // Create Vertex Buffer Array
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);

  // Bind the VAO so VBO config/state gets saved into it.
  glBindVertexArray(VAO);

  // Bind the VBO so any buffer calls now will configure it.
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  // Copies vertices data into the currently bound buffer (VBO)
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Tells the GPU how the vertex data is structured and how to interpret it.
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // VERTEX SHADER

  // GLSL language.
  char * vertexShaderSource = readFile("shaders/vertex.vert");

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  // Compile and attach GLSL commands to shader object ID.
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  free(vertexShaderSource);

  // FRAGMENT SHADER
  char * fragmentShaderSource = readFile("shaders/fragment.frag");

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  // Compile and attach fragment shader, same proces as vertex.
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  free(fragmentShaderSource);

  // Link the 2 shaders and activate the shader program result.
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // Set current active shader program.
  glUseProgram(shaderProgram);


  // display.render = render;

  // showDisplay(&display);


  while (!glfwWindowShouldClose(display.window)) {
    glfwPollEvents();

    // if (display->render) {
      glUseProgram(shaderProgram);
      glBindVertexArray(VAO);

      // Draw the triangle
      glDrawArrays(GL_TRIANGLES, 0, 3);
    // }

    glfwSwapBuffers(display.window);
  }

  // As we've linked our shaders into a program, it is unneccessary to keep them.
  // Deleted from GPU memory?
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return 0;
}
