#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <chrono>

class Graphics {
	private:
		GLFWwindow* window;
		GLuint VAO;
		GLuint VBO;
		GLuint EBO;
		GLuint vert;
		GLuint frag;
		GLuint program;
		int shaderCount = 0;
		GLuint shaders[];
	public:
		GLFWwindow* Initialize(int width, int height, const char* title, GLFWmonitor* monitor);
		void Generate(GLuint vao, GLuint vbo, GLuint ebo);
		void BufferVBO(float *vertices, int size, GLenum drawType);
		void BufferEBO(GLuint *elements, int size, GLenum drawType);
		GLuint CreateShader(GLenum shaderType, const GLchar* source);
		void CompileShaders();
		GLuint ConfigureProgram(GLuint vertShader, GLuint fragShader);
		void BeginDraw();
		void EndDraw();
		void PollEvents();
		void Destroy();
};


#endif
