#pragma once
#include <glm/glm.hpp>

class Color {
public:
	static glm::vec3 black;
	static glm::vec3 white;
	static glm::vec3 red;
	static glm::vec3 green;
	static glm::vec3 blue;
	static glm::vec3 coral;

};

glm::vec3 Color::black = glm::vec3(0.0f);
glm::vec3 Color::white = glm::vec3(1.0f);
glm::vec3 Color::red = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 Color::green = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 Color::blue = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 Color::coral = glm::vec3(1.0f, 0.5f, 0.31f);
