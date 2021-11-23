#ifndef GRAPHICS_OGL_HPP
#define GRAPHICS_OGL_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <chrono>

class Graphics {
	private:
		GLFWwindow* window;
		int shaderCount = 0;
		GLuint shaders[];
	public:
		GLFWwindow* Initialize(int width, int height, const char* title, GLFWmonitor* monitor) {
			window = glfwCreateWindow(width, height, title, monitor, NULL);
			if (!window) {
				glfwTerminate();
				return nullptr;
			}
    		glfwMakeContextCurrent(window);
			glewExperimental = GL_TRUE;
			if (glewInit() != GL_NO_ERROR) {
				//printf("Failed to initialize GLEW\n");
				return nullptr;
			}
			return window;
		}
		void Generate(GLuint vao, GLuint vbo, GLuint ebo) {
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);

			glGenBuffers(1, &ebo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		}
		void BufferVBO(std::vector<float> vertices, GLenum drawType) {
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, drawType);
		}
		void BufferEBO(std::vector<GLuint> elements, GLenum drawType) {
			printf("%i\n", sizeof(elements));
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, drawType);
		}
		GLuint CreateShader(GLenum shaderType, const GLchar* source) {
			GLuint shader = glCreateShader(shaderType);
			glShaderSource(shader, 1, &source, NULL);
			shaders[shaderCount++] = shader;
			return shader;
		}
		void CompileShaders() {
			for (int i = 0; i < shaderCount; i++) {
				GLuint shader = shaders[i];
				glCompileShader(shader);
				GLint isCompiled = 0;
				glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
				if (isCompiled == GL_FALSE) {
					printf("Failed to compile shader\n");
				}
			}
		}
};


#endif
