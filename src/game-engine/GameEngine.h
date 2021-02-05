#pragma once
#include "Camera.h"
#include "Controls.h"

class GameEngine {
public:
	unsigned int SCREEN_WIDTH = 800;
	unsigned int SCREEN_HEIGHT = 800;
	GLFWwindow* window;
	Camera camera;
	Controls controls;
	float deltaTime = 0.0f;	// Time between current frame and last frame
	float lastFrame = 0.0f; // Time of last frame
	glm::vec3 coral = glm::vec3(1.0f, 0.5f, 0.31f);
	glm::vec3 white = glm::vec3(1.0f);

	GameEngine(GLFWwindow* window = nullptr) 
	{
		this->window = window;
	}

	void initialize() 
	{
		glEnable(GL_DEPTH_TEST);

		// Camera & controls
		camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT);
		controls = Controls(&camera);

		// Load texture
		unsigned int texture = Texture::Load("wall.jpg", true);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void run() 
	{
		// Load shader
		Shader shader("shader.vert", "shader.frag");
		shader.use();
		shader.setInt("iChannel0", 0);

		CubePrimitive cubePrimitive;
		Light light(cubePrimitive, glm::vec3(0.0f), coral);
		light.scale = glm::vec3(0.2f);

		// Load light shader
		Shader lightShader("light.vert", "light.frag");

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE

		Cube cubes[] =
		{
			Cube(glm::vec3(0.0f,  0.0f,  5.0f)),
			Cube(glm::vec3(2.0f,  5.0f, -15.0f)),
			Cube(glm::vec3(-1.5f, -2.2f, -2.5f)),
			Cube(glm::vec3(-3.8f, -2.0f, -12.3f)),
			Cube(glm::vec3(2.4f, -0.4f, -3.5f)),
			Cube(glm::vec3(-1.7f,  3.0f, -7.5f)),
			Cube(glm::vec3(1.3f, -2.0f, -2.5f)),
			Cube(glm::vec3(1.5f,  2.0f, -2.5f)),
			Cube(glm::vec3(1.5f,  0.2f, -1.5f)),
			Cube(glm::vec3(-1.3f,  1.0f, -1.5f))
		};
		for (unsigned int i = 0; i < 10; i++)
		{
			float angle = glm::radians(20.0f * i);
			cubes[i].rotation = glm::vec3(angle, 0.3f * angle, 0.5f * angle);
			cubes[i].primitive = cubePrimitive;
		}

		while (!glfwWindowShouldClose(window))
		{
			float currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			// process the input (keyboard, mouse)
			controls.HandleKeyboard(window, deltaTime);

			// render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Set camera view and projection matrix.
			glm::mat4 view = camera.getViewMatrix();
			glm::mat4 projection = camera.getProjectionMatrix();

			// Light position
			float lx = 2.0f * (cos(glfwGetTime()) * 0.5 + 0.5);
			float ly = 2.0f * (sin(glfwGetTime()) * 0.5 + 0.5);
			light.position = glm::vec3(lx, 0.0f, -5.0f - ly);

			// Draw cubes
			shader.use();
			shader.setMat4("projection", projection);
			shader.setMat4("view", view);
			shader.setVec3("lightPos", light.position);
			shader.setVec3("viewPos", camera.position);
			shader.setFloat("iTime", (float)glfwGetTime());
			shader.setVec3("objectColor", coral);
			shader.setVec3("lightColor", white);
			cubes[0].primitive.bind();
			for (unsigned int i = 0; i < 10; i++)
			{
				glm::mat4 model = cubes[i].getModelMatrix();
				shader.setMat4("model", model);
				cubes[i].draw();
			}

			// Draw the light
			glm::mat4 model = light.getModelMatrix();
			lightShader.use();
			lightShader.setMat4("view", view);
			lightShader.setMat4("model", model);
			lightShader.setMat4("projection", projection);
			light.bind();
			light.draw();

			// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			// glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// glfw: swap buffers and poll IO events (keys down/up)
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		// Clean-up
		glDeleteProgram(shader.ID);
	}
};