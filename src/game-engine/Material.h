#pragma once
#include <glm/glm.hpp>

class Material {
public:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
	
	Material()
	{
		ambient = glm::vec3(0.0f);
		diffuse = glm::vec3(1.0f);
		specular = glm::vec3(1.0f);
		shininess = 32.0f;
	}

	Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess)
	{
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->shininess = shininess;
	}

	static Material emerald;
	static Material jade;
	static Material obsidian;
	static Material pearl;
	static Material ruby;
	static Material turquoise;
	static Material brass;
	static Material bronze;
	static Material chrome;
	static Material copper;
	static Material gold;
	static Material silver;
	static Material black_plastic;
	static Material cyan_plastic;
	static Material green_plastic;
	static Material red_plastic;
	static Material white_plastic;
	static Material yellow_plastic;
	static Material black_rubber;
	static Material cyan_rubber;
	static Material green_rubber;
	static Material red_rubber;
	static Material white_rubber;
	static Material yellow_rubber;

};

Material Material::emerald = Material(glm::vec3(0.0215f, 0.1745f, 0.0215f), glm::vec3(0.07568f, 0.61424f, 0.07568f), glm::vec3(0.633f, 0.727811f, 0.633f), 76.8f);
Material Material::jade = Material(glm::vec3(0.135f, 0.2225f, 0.1575), glm::vec3(0.54f, 0.89f, 0.63), glm::vec3(0.316228f, 0.316228f, 0.316228), 12.8f);
Material Material::obsidian = Material(glm::vec3(0.05375f, 0.05f, 0.06625), glm::vec3(0.18275f, 0.17f, 0.22525), glm::vec3(0.332741f, 0.328634f, 0.346435), 38.4f);
Material Material::pearl = Material(glm::vec3(0.25f, 0.20725f, 0.20725), glm::vec3(1.0f, 0.829f, 0.829), glm::vec3(0.296648f, 0.296648f, 0.296648), 11.264f);
Material Material::ruby = Material(glm::vec3(0.1745f, 0.01175f, 0.01175), glm::vec3(0.61424f, 0.04136f, 0.04136), glm::vec3(0.727811f, 0.626959f, 0.626959), 76.8f);
Material Material::turquoise = Material(glm::vec3(0.1f, 0.18725f, 0.1745), glm::vec3(0.396f, 0.74151f, 0.69102), glm::vec3(0.297254f, 0.30829f, 0.306678), 12.8f);
Material Material::brass = Material(glm::vec3(0.329412f, 0.223529f, 0.027451), glm::vec3(0.780392f, 0.568627f, 0.113725), glm::vec3(0.992157f, 0.941176f, 0.807843), 27.89743616f);
Material Material::bronze = Material(glm::vec3(0.2125f, 0.1275f, 0.054), glm::vec3(0.714f, 0.4284f, 0.18144), glm::vec3(0.393548f, 0.271906f, 0.166721), 25.6f);
Material Material::chrome = Material(glm::vec3(0.25f, 0.25f, 0.25), glm::vec3(0.4f, 0.4f, 0.4), glm::vec3(0.774597f, 0.774597f, 0.774597), 76.8f);
Material Material::copper = Material(glm::vec3(0.19125f, 0.0735f, 0.0225), glm::vec3(0.7038f, 0.27048f, 0.0828), glm::vec3(0.256777f, 0.137622f, 0.086014), 12.8f);
Material Material::gold = Material(glm::vec3(0.24725f, 0.1995f, 0.0745), glm::vec3(0.75164f, 0.60648f, 0.22648), glm::vec3(0.628281f, 0.555802f, 0.366065), 51.2f);
Material Material::silver = Material(glm::vec3(0.19225f, 0.19225f, 0.19225), glm::vec3(0.50754f, 0.50754f, 0.50754), glm::vec3(0.508273f, 0.508273f, 0.508273), 51.2f);
Material Material::black_plastic = Material(glm::vec3(0.0f, 0.0f, 0), glm::vec3(0.01f, 0.01f, 0.01), glm::vec3(0.5f, 0.5f, 0.5), 32.0f);
Material Material::cyan_plastic = Material(glm::vec3(0.0f, 0.1f, 0.06), glm::vec3(0.0f, 0.50980392f, 0.50980392), glm::vec3(0.50196078f, 0.50196078f, 0.50196078), 32.0f);
Material Material::green_plastic = Material(glm::vec3(0.0f, 0.0f, 0), glm::vec3(0.1f, 0.35f, 0.1), glm::vec3(0.45f, 0.55f, 0.45), 32.0f);
Material Material::red_plastic = Material(glm::vec3(0.0f, 0.0f, 0), glm::vec3(0.5f, 0.0f, 0), glm::vec3(0.7f, 0.6f, 0.6), 32.0f);
Material Material::white_plastic = Material(glm::vec3(0.0f, 0.0f, 0), glm::vec3(0.55f, 0.55f, 0.55), glm::vec3(0.7f, 0.7f, 0.7), 32.0f);
Material Material::yellow_plastic = Material(glm::vec3(0.0f, 0.0f, 0), glm::vec3(0.5f, 0.5f, 0), glm::vec3(0.6f, 0.6f, 0.5), 32.0f);
Material Material::black_rubber = Material(glm::vec3(0.02f, 0.02f, 0.02), glm::vec3(0.01f, 0.01f, 0.01), glm::vec3(0.4f, 0.4f, 0.4), 10.0f);
Material Material::cyan_rubber = Material(glm::vec3(0.0f, 0.05f, 0.05), glm::vec3(0.4f, 0.5f, 0.5), glm::vec3(0.04f, 0.7f, 0.7), 10.0f);
Material Material::green_rubber = Material(glm::vec3(0.0f, 0.05f, 0), glm::vec3(0.4f, 0.5f, 0.4), glm::vec3(0.04f, 0.7f, 0.04), 10.0f);
Material Material::red_rubber = Material(glm::vec3(0.05f, 0.0f, 0), glm::vec3(0.5f, 0.4f, 0.4), glm::vec3(0.7f, 0.04f, 0.04), 10.0f);
Material Material::white_rubber = Material(glm::vec3(0.05f, 0.05f, 0.05), glm::vec3(0.5f, 0.5f, 0.5), glm::vec3(0.7f, 0.7f, 0.7), 10.0f);
Material Material::yellow_rubber = Material(glm::vec3(0.05f, 0.05f, 0), glm::vec3(0.5f, 0.5f, 0.4), glm::vec3(0.7f, 0.7f, 0.04), 10.0f);
