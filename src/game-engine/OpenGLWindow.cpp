#include "OpenGLWindow.h"
#include <iostream>

OpenGLWindow::OpenGLWindow(int width, int height, bool fullScreen)
{
	this->width = width;
	this->height = height;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	whnd = glfwCreateWindow(width, height, "GameEngineOpenGL", NULL, NULL);
	if (whnd == NULL)
	{
		glfwTerminate();
		std::cout << "Failed to create GLFW window" << std::endl;
	}

	glfwMakeContextCurrent(whnd);
	glfwSetFramebufferSizeCallback(whnd, framebuffer_size_callback);

	//if (!CreateGLFWWindow())
	//{
	//	
	//	return -1;
	//}
}

void OpenGLWindow::setWindowed()
{
}

void OpenGLWindow::setFullScreen()
{
}

void OpenGLWindow::framebuffer_size_callback(GLFWwindow* whnd, int width, int height)
{
	//this->width = width;
	//this->height = height;
}
