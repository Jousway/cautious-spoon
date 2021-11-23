#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <chrono>

class Quad {
public:
	Quad(int X, int Y, int W, int H) : 
		Width(W), Height(H), LocX(X), LocY(Y) {};

private:
	int Width;
	int Height;
	int LocX;
	int LocY;
};

class Graphics {
	private:
		GLFWwindow* window;
		GLuint VAO, VBO, EBO, vert, frag, program;

		std::vector<Quad> Quads;
		std::vector<GLuint> shaders;
	public:
		GLFWwindow* Initialize(int width, int height, const char* title, GLFWmonitor* monitor);
		void Generate(GLuint vao, GLuint vbo, GLuint ebo);

		template<class A>
		void Buffer(int Type, std::vector<A> input, GLenum drawType) {
			printf("SIZE: %i\n", static_cast<int>(input.size() * sizeof(A)));
			glBufferData(Type, input.size() * sizeof(A), input.data(), drawType);
		}

		GLuint CreateShader(GLenum shaderType, const GLchar* source);
		void CompileShaders();
		GLuint ConfigureProgram(GLuint vertShader, GLuint fragShader);
		void GenQuad(int X, int Y, int W, int H);
		void Update();
		void BeginDraw();
		void EndDraw();
		void PollEvents();
		void Destroy();
};


#endif
