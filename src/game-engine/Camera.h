#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float ZOOM = 45.0f;
const float FAR = 100.0f;
const float NEAR = 0.1f;

class Camera
{
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	float yaw;
	float pitch;
	float fov;
	float aspectRatio;
	float far;
	float near;
	Camera(glm::vec3 position = glm::vec3(0.0f), float aspectRatio = 1.0f) : front(glm::vec3(0.0f, 0.0f, -1.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)), yaw(YAW), pitch(PITCH), fov(ZOOM), near(NEAR), far(FAR)
	{ 
		this->position = position;
		this->aspectRatio = aspectRatio;
	} 
	glm::mat4 getViewMatrix()
	{
		return glm::lookAt(position, position + front, up);
	}
	glm::mat4 getProjectionMatrix()
	{
		return glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f);
	}
	void setFieldOfView(float fov)
	{
		if (fov < 20.0f)
		{
			fov = 20.0f;
		}
		if (fov > 45.0f)
		{
			fov = 45.0f;
		}
		this->fov = fov;
	}
};

