#include "Main.hpp"

int main(int argc, char* argv[])
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(Settings::Width, Settings::Height, Settings::Title, nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Load Test Model */
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


	// friendly square .u.
	Quad q1;
	Quad q2;
	q1.Position(Settings::Width * 0.25, Settings::Height * 0.5);
	q1.Size(64.0, 64.0);
	q2.Position(Settings::Width * 0.75, Settings::Height * 0.5);
	q2.Size(64.0, 64.0);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* Render here */
		q1.Draw();
		q2.Draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
