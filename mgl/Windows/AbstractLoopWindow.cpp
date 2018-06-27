#include "../MyGraphicsLibrary/MGL/OpenGL/OpenGL_Dependency/OpenGL.h"
#include "AbstractLoopWindow.hpp"

int mgl::AbstractLoopWindow::loop() {
	initializeEventHandling();
	initializeRenderProcess();

	int width, height;
	glfwGetFramebufferSize(window(), &width, &height);
	resize(width, height);

	while (!glfwWindowShouldClose(window())) {
		renderProcess();

		glfwSwapBuffers(window());
		if (isAutoUpdated)
			glfwPollEvents();
		else
			glfwWaitEvents();
	}
	clearRenderProcess();
	return 0;
}
