#pragma warning(push, 4)
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Texture.h"
#include "Controls.h"
#include "Primitive.h"
#include "GameEngine.h"
#pragma warning(pop)

GLFWwindow* window = nullptr;
GameEngine engine;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

bool CreateGLFWWindow()
{
	// glfw window creation
	window = glfwCreateWindow(engine.SCREEN_WIDTH, engine.SCREEN_WIDTH, "GameEngineOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return true;
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!CreateGLFWWindow())
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		return -1;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	engine = GameEngine(window);
	engine.initialize();
	engine.run();
	glfwTerminate();
	return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	engine.controls.HandleMouse(window, xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	engine.controls.HandleScroll(window, xoffset, yoffset);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	engine.SCREEN_WIDTH = width;
	engine.SCREEN_HEIGHT = height;
	glViewport(0, 0, width, height);
}
