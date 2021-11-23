#include "Graphics.hpp"


GLFWwindow* Graphics::Initialize(int width, int height, const char* title, GLFWmonitor* monitor) {
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
void Graphics::Generate(GLuint vao, GLuint vbo, GLuint ebo) {
	VAO = vao;
	VBO = vbo;
	EBO = ebo;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}
void Graphics::BufferVBO(float *vertices, int size, GLenum drawType) {
	glBufferData(GL_ARRAY_BUFFER, size, vertices, drawType);
}
void Graphics::BufferEBO(GLuint *elements, int size, GLenum drawType) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, elements, drawType);
}
GLuint Graphics::CreateShader(GLenum shaderType, const GLchar* source) {
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	shaders[shaderCount++] = shader;
	return shader;
}
void Graphics::CompileShaders() {
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
GLuint Graphics::ConfigureProgram(GLuint vertShader, GLuint fragShader) {
	vert = vertShader;
	frag = fragShader;
	program = glCreateProgram();
	glAttachShader(program, vert);
	glAttachShader(program, frag);
	glLinkProgram(program);
	glUseProgram(program);
	return program;
}
void Graphics::BeginDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
}
void Graphics::EndDraw() {
	glfwSwapBuffers(window);
}
void Graphics::PollEvents() {
	glfwPollEvents();
}
void Graphics::Destroy() {
	/* Delete program */
	glDeleteProgram(program);
	/* Delete shaders */
	glDeleteShader(frag);
	glDeleteShader(vert);
	/* Delete buffers */
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	/* Delete vertex arrays */
	glDeleteVertexArrays(1, &VAO);
	/* Kill window */
	glfwTerminate();
}