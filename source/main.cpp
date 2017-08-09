#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "display.h"
#include "shader.h"
// #include "image.h"
#include "texture.h"

// float vertices[] = {
//   // positions         // colors
//    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,    // top
//    0.0f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // bottom
// };

float vertices[] = {
   // positions       // colors         // Texture positions
   0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
   0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
  -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
  -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

int main() {
  Display display;

  initDisplay(&display);

//  Image image = createImage("box");

  // Create Vertex Buffer Object
  unsigned int VBO;
  glGenBuffers(1, &VBO);

  // Create Vertex Buffer Array
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);

  // Create Ekement Buffer Object
  unsigned int EBO;
  glGenBuffers(1, &EBO);

  // Bind the VAO so EBO + VBO config/state gets saved into it.
  glBindVertexArray(VAO);

  // Bind the VBO so any buffer calls now will configure it.
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  // Copies vertices data into the currently bound buffer (VBO)
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Bind the EBO so any buffer calls now will configure it.
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  // Copy indicies data to currently bound buffer()
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // Tells the GPU how the vertex data is structured and how to interpret it.
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  // Create the shaders needed.
  Shader vertexShader = createShader("vertex", GL_VERTEX_SHADER);
  Shader fragmentShader = createShader("fragment", GL_FRAGMENT_SHADER);

  // Link the 2 shaders and activate the shader program result.
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader.id);
  glAttachShader(shaderProgram, fragmentShader.id);
  glLinkProgram(shaderProgram);

  // Set current active shader program.
  glUseProgram(shaderProgram);


  // Texture
  Texture texture = createTexture("box");

  //
//  int width;
//  int height;
  // GLuint texture = loadTexture("images/box.png", &width, &height);


  // display.render = render;

  // showDisplay(&display);


  while (!glfwWindowShouldClose(display.window)) {
      glfwPollEvents();

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

    // if (display->render) {
      glUseProgram(shaderProgram);

      glBindVertexArray(VAO);
      glBindTexture(GL_TEXTURE_2D, texture.id);
      // Draw the triangle
      // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

      // glBindVertexArray(VAO);
      // glDrawArrays(GL_TRIANGLES, 0, 3);
    // }

    glfwSwapBuffers(display.window);
  }

  // As we've linked our shaders into a program, it is unneccessary to keep them.
  // Deleted from GPU memory?
  glDeleteShader(vertexShader.id);
  glDeleteShader(fragmentShader.id);

  return 0;
}
