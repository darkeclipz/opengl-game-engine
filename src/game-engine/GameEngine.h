#pragma once
#include "Camera.h"
#include "Controls.h"
#include "Color.h"
#include "Material.h"

class GameEngine {
public:
	unsigned int SCREEN_WIDTH = 800;
	unsigned int SCREEN_HEIGHT = 800;
	GLFWwindow* window;
	Camera camera;
	Controls controls;
	float deltaTime = 0.0f;	// Time between current frame and last frame
	float lastFrame = 0.0f; // Time of last frame

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
		unsigned int texture = Texture::load("wall.jpg", true);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void run() 
	{
		// Load shader
		Shader shader("shader.vert", "shader.frag");
		shader.use();
		shader.set_int("iChannel0", 0);

		CubePrimitive cubePrimitive;
		Light light(cubePrimitive, glm::vec3(0.0f), Color::coral);
		light.scale = glm::vec3(0.2f);

		// Load light shader
		Shader lightShader("light.vert", "light.frag");

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE

		Cube cubes[] =
		{
			Cube(glm::vec3(0.0f,  0.0f,  5.0f), Material::emerald),
			Cube(glm::vec3(2.0f,  5.0f, -15.0f), Material::pearl),
			Cube(glm::vec3(-1.5f, -2.2f, -2.5f), Material::bronze),
			Cube(glm::vec3(-3.8f, -2.0f, -12.3f), Material::gold),
			Cube(glm::vec3(2.4f, -0.4f, -3.5f), Material::chrome),
			Cube(glm::vec3(-1.7f,  3.0f, -7.5f), Material::cyan_plastic),
			Cube(glm::vec3(1.3f, -2.0f, -2.5f), Material::red_plastic),
			Cube(glm::vec3(1.5f,  2.0f, -2.5f), Material::green_rubber),
			Cube(glm::vec3(1.5f,  0.2f, -1.5f), Material::yellow_rubber),
			Cube(glm::vec3(-1.3f,  1.0f, -1.5f), Material::brass)
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
			glm::mat4 view = camera.view_matrix();
			glm::mat4 projection = camera.projection_matrix();

			// Light position
			float lx = 2.0f * (cos(glfwGetTime()) * 0.5 + 0.5);
			float ly = 2.0f * (sin(glfwGetTime()) * 0.5 + 0.5);
			light.position = glm::vec3(lx, 0.0f, -5.0f - ly);

			// Draw cubes
			shader.use();
			shader.set_mat4("projection", projection);
			shader.set_mat4("view", view);
			shader.set_vec3("lightPos", light.position);
			shader.set_vec3("viewPos", camera.position);
			shader.set_float("iTime", (float)glfwGetTime());
			shader.set_vec3("lightColor", Color::white);
			cubes[0].primitive.bind();
			for (unsigned int i = 0; i < 10; i++)
			{
				shader.set_vec3("material.ambient", cubes[i].material.ambient);
				shader.set_vec3("material.diffuse", cubes[i].material.diffuse);
				shader.set_vec3("material.specular", cubes[i].material.specular);
				shader.set_float("material.shininess", cubes[i].material.shininess);

				glm::mat4 model = cubes[i].model_matrix();
				shader.set_mat4("model", model);
				cubes[i].draw();
			}

			// Draw the light
			glm::mat4 model = light.model_matrix();
			lightShader.use();
			lightShader.set_mat4("view", view);
			lightShader.set_mat4("model", model);
			lightShader.set_mat4("projection", projection);
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