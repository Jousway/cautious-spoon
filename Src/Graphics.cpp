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

GLuint Graphics::CreateShader(GLenum shaderType, const GLchar* source) {
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	shaders.push_back(shader);
	return shader;
}
void Graphics::CompileShaders() {
	for (auto& shader : shaders)
	{
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

Quad Graphics::GenQuad(float X, float Y, float W, float H)
{
	Quads.push_back(Quad(X, Y, W, H));
	return Quads[Quads.size() - 1];
}

void Graphics::Update()
{
	for (auto& Q : Quads)
	{
		std::vector<float> verts = {
			Q.LocX, Q.LocY, 1.0f, 1.0f, 1.0f,
			Q.LocX + Q.Width, Q.LocY, 1.0f, 1.0f, 1.0f,
			Q.LocX + Q.Width, Q.LocY + Q.Height, 1.0f, 1.0f, 1.0f,
			Q.LocX, Q.LocY + Q.Height, 1.0f, 1.0f, 1.0f
		};
		Buffer(GL_ARRAY_BUFFER, verts, GL_STREAM_DRAW);
		std::vector<GLuint> elems = {
			0, 1, 2,
			2, 3, 0
		};
		Buffer(GL_ELEMENT_ARRAY_BUFFER, elems, GL_STREAM_DRAW);
		glDrawElements(GL_TRIANGLES, elems.size() * sizeof(GLuint), GL_UNSIGNED_INT, 0);
	}
}
