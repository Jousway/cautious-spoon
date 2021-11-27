#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <chrono>

class Quad {
public:
	Quad(int X = 0, int Y = 0, int W = 0, int H = 0) : 
		Width(static_cast<float>(W)), Height(static_cast<float>(H)), LocX(static_cast<float>(X)), LocY(static_cast<float>(Y)), Colours({1.f,1.f,1.f}) {};
	float Width, Height, LocX, LocY;

	void Diffuse(std::array<float, 3> Colours)
	{
		this->Colours = Colours;
	}

	std::array<float, 3> Colours;
};

class Sprite : public Quad {
private:
	GLubyte* tex;
public:
	Sprite(int X = 0, int Y = 0, int W = 0, int H = 0, std::string path = "") :
		TexturePath(path)
		{
			/*
			int texWidth, texHeight, nrChannels;
			tex = stbi_load(path.c_str(), &texWidth, &texHeight, &nrChannels, 0);
			if (!tex) {
				printf("ERROR: what \"%s\"", path.c_str());
			}
			*/
			
		};
	std::string TexturePath;
};

class Graphics {
private:
	GLFWwindow* window;
	GLuint VAO, VBO, EBO, vert, frag, program;
	float ScreenWidth, ScreenHeight;

	std::vector<GLuint> shaders;
public:
	GLFWwindow* Initialize(int width, int height, const char* title, GLFWmonitor* monitor);
	void Generate(GLuint vao, GLuint vbo, GLuint ebo);

	template<class A>
	void Buffer(int Type, std::vector<A> input, GLenum drawType) {
		//printf("SIZE: %i\n", static_cast<int>(input.size() * sizeof(A)));
		glBufferData(Type, input.size() * sizeof(A), input.data(), drawType);
	}

	GLuint CreateShader(GLenum shaderType, const GLchar* source);
	void CompileShaders();
	GLuint ConfigureProgram(GLuint vertShader, GLuint fragShader);
	void GenQuad(std::string Name, int X, int Y, int W, int H);
	void GenSprite(std::string Name, int X, int Y, int W, int H, std::string path);
	void Update();
	void BeginDraw();
	void EndDraw();
	void PollEvents();
	void Destroy();

	std::map<std::string, Quad> Quads;
	std::map<std::string, Sprite> Sprites;
};


#endif
