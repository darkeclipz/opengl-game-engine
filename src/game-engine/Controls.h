#pragma once
#include "Camera.h"
#include <GLFW/glfw3.h>

class Controls {
protected:
	float lastMousePositionX = 0.0f;
	float lastMousePositionY = 0.0f;
	bool firstMouseMovement = true;

public:
	Camera* camera;
	Controls(Camera* camera = nullptr) 
	{
		this->camera = camera;
	}

	void HandleKeyboard(GLFWwindow* window, float deltaTime)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}

		const float cameraSpeed = 2.5f * deltaTime;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			camera->position += cameraSpeed * camera->front;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			camera->position -= cameraSpeed * camera->front;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			camera->position -= glm::normalize(glm::cross(camera->front, camera->up)) * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			camera->position += glm::normalize(glm::cross(camera->front, camera->up)) * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			camera->position += camera->up * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		{
			camera->position -= camera->up * cameraSpeed;
		}
	}

	void HandleMouse(GLFWwindow* window, double x, double y)
	{
		if (firstMouseMovement)
		{
			lastMousePositionX = x;
			lastMousePositionY = y;
			firstMouseMovement = false;
		}

		float xoffset = x - lastMousePositionX;
		float yoffset = lastMousePositionY - y;
		lastMousePositionX = x;
		lastMousePositionY = y;

		float sensitivity = 0.1f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		camera->yaw += xoffset;
		camera->pitch += yoffset;

		if (camera->pitch > 89.0f)
		{
			camera->pitch = 89.0f;
		}
		if (camera->pitch < -89.0f)
		{
			camera->pitch = -89.0f;
		}

		glm::vec3 direction;
		direction.x = cos(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
		direction.y = sin(glm::radians(camera->pitch));
		direction.z = sin(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
		camera->front = glm::normalize(direction);
	}

	void HandleScroll(GLFWwindow* window, double xoffset, double yoffset)
	{
		camera->setFieldOfView(camera->fov - (float)yoffset);
	}
};