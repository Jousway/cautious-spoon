#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <chrono>
#include "GLTFLoader.hpp"

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

/*
class Model {
	private:
		tinygltf::Model model;
		tinygltf::Model LoadModel(std::string path) {
			std::string err;
			std::string warn;
			bool res = GLTFLoader.LoadASCIIFromFile(&model, &err, &warn, path);
			if (!warn.empty()) {
				printf("WARN: %s\n", warn.c_str());
			}
			if (!err.empty()) {
				printf("ERROR: %s\n", err.c_str());
			}
			if (!res) {
				printf("Cannot load model at path %s\n", path.c_str());
			}
			return model;
		}
	public:
		Model(std::string path, int X = 0, int Y = 0) :
			LocX(static_cast<float>(X)), LocY(static_cast<float>(Y)), Path(path), Colours({1.f,1.f,1.f}) {};
		float LocX, LocY;
		std::string Path;

		void Diffuse(std::array<float, 3> Colours)
		{
			this->Colours = Colours;
		}

		std::array<float, 3> Colours;
		void Draw() {
			assert(model.scenes.size() > 0);
			int scene_to_display = model.defaultScene > -1 ? model.defaultScene : 0;
			const tinygltf::Scene &scene = model.scenes[scene_to_display];
			for (size_t i = 0; i < scene.nodes.size(); i++) {
				
			}
		}
};
//*/

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
		void GenQuad(std::string Name ,int X, int Y, int W, int H);
		void Update();
		void BeginDraw();
		void EndDraw();
		void PollEvents();
		void Destroy();

		std::map<std::string, Quad> Quads;
		//std::map<std::string, Model> Models;
};


#endif
