#include "Main.hpp"
#include "Graphics.hpp"

/* Vertex shader */
const GLchar* vertSrc = R"glsl(
	#version 150 core
	in vec2 position;
	in vec3 color;
	out vec3 Color;
	void main() {
		Color = color;
		gl_Position = vec4(position, 0.0, 1.0);
	}
)glsl";
/* Fragment shader */
const GLchar* fragSrc = R"glsl(
	#version 150 core
	in vec3 Color;
	out vec4 outColor;
	uniform float time;
	void main() {
		float col = (sin(time * 4.0) + 1.0) / 2.0;
		outColor = vec4(Color * col, 1.0);
	}
)glsl";

int main(int argc, char* argv[])
{

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    Graphics display;
	GLFWwindow* window = display.Initialize(640, 480, "SPOON", NULL);
    if (!window) {
		printf("Unable to create window\n");
        return -1;
    }


    /* Load Test Model */
	/*
    bool ret = loader.LoadASCIIFromFile(&model, &err, &warn, "Test.gltf");

    if (!warn.empty()) {
        printf("Warn: %s\n", warn.c_str());
    }

    if (!err.empty()) {
        printf("Err: %s\n", err.c_str());
    }

    if (!ret) {
        printf("Failed to parse glTF\n");
        return -1;
    }
	*/


	/* Create buffer objects */
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ebo = 0;
	display.Generate(vao, vbo, ebo);


	/* Set up vertices */
	/*
	std::vector<float> vertices = {
		-0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 1.0f, 1.0f, 1.0f
	};
	display.Buffer(GL_ARRAY_BUFFER, vertices, GL_STATIC_DRAW);
	*/

	/* Set up elements */
	/*
	std::vector<GLuint> elements = {
		0, 1, 2,
		2, 3, 0
	};
	display.Buffer(GL_ELEMENT_ARRAY_BUFFER, elements, GL_STATIC_DRAW);
	*/


	Quad qOne = display.GenQuad(-0.25f, -0.25f, 0.25f, 0.25f);
	Quad qTwo = display.GenQuad(0.25f, 0.25f, 0.25f, 0.25f);


	/* Create and compile shaders */
	GLuint vertShader = display.CreateShader(GL_VERTEX_SHADER, vertSrc);
	GLuint fragShader = display.CreateShader(GL_FRAGMENT_SHADER, fragSrc);
	display.CompileShaders();

	/* Create program and attach shaders */
	GLuint shaderProg = display.ConfigureProgram(vertShader, fragShader);

	/* Vert shader position */
	GLint posAttrib = glGetAttribLocation(shaderProg, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);

	/* Vert shader color */
	GLint colAttrib = glGetAttribLocation(shaderProg, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	/* Uniform time */
	auto t_start = std::chrono::steady_clock::now();
	auto t_now = std::chrono::steady_clock::now();
	float time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();
	GLint uniTime = glGetUniformLocation(shaderProg, "time");
	glUniform1f(uniTime, 0.0f);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		/* Check escape key press */
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		
		/* Refresh uniform time */
		t_now = std::chrono::steady_clock::now();
		time = std::chrono::duration_cast<std::chrono::duration<float>>(t_now - t_start).count();
		glUniform1f(uniTime, time);

        /* Render here */
        display.BeginDraw();

		/* i did it dad */
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		display.Update();

        /* Swap front and back buffers */
        display.EndDraw();

        /* Poll for and process events */
		display.PollEvents();
    }

	display.Destroy();
    return 0;
}
