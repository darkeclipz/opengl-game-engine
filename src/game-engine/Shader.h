#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	// The program ID.
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	// Use/active the shader.
	void use();

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, glm::vec3& v) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setMat4(const std::string& name, glm::mat4& m) const;
};