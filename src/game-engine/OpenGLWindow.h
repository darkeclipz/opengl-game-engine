#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLWindow
{
public:
	OpenGLWindow(int width, int height, bool fullScreen = false);
	int width;
	int height;
	GLFWwindow* whnd;
	bool isFullScreen = false;
	void setWindowed();
	void setFullScreen();
	void framebuffer_size_callback(GLFWwindow* whnd, int width, int height);

private:
	int windowedWidth;
	int windowedHeight;
	int windowedX;
	int windowedY;
};

