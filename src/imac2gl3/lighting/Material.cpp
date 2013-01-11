#include "../../../include/imac2gl3/lighting/Material.hpp"
#include <cstring>
#include <string>
#include <GL/glew.h>


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Material::Material(glm::vec3 _ka, glm::vec3 _kd, glm::vec3 _ks, float _shininess) {
	Ka.x = _ka.x;
	Ka.y = _ka.y;
	Ka.z = _ka.z;
	Kd.x = _kd.x;
	Kd.y = _kd.y;
	Kd.z = _kd.z;
	Ks.x = _ks.x;
	Ks.y = _ks.y;
	Ks.z = _ks.z;
	shininess = _shininess;
}

glm::vec3 Material::getKa() {
		return Ka;
}
glm::vec3 Material::getKd() {
		return Kd;
}
glm::vec3 Material::getKs() {
		return Ks;
}
float Material::getshininess() {
		return shininess;
}

GLint MaterialUniform::getKaLocation() {
		return KaLocation;
}
GLint MaterialUniform::getKdLocation() {
		return KdLocation;
}
GLint MaterialUniform::getKsLocation() {
		return KsLocation;
}
GLint MaterialUniform::getshininessLocation() {
		return shininessLocation;
}

void MaterialUniform::getLocations(const char* uniform, GLuint program) {
	glGetUniformLocation(program, (std::string(uniform) + ".ambient").c_str());
	glGetUniformLocation(program, (std::string(uniform) + ".diffuse").c_str());
	glGetUniformLocation(program, (std::string(uniform) + ".specular").c_str());
	glGetUniformLocation(program, (std::string(uniform) + ".shininess").c_str());
}

void MaterialUniform::sendMaterial( Material* material) {

	glUniform3f(this->getKaLocation(), material->getKa().x, material->getKa().y, material->getKa().z);
	glUniform3f(this->getKdLocation(), material->getKd().x, material->getKd().y, material->getKd().z);
	glUniform3f(this->getKsLocation(), material->getKs().x, material->getKs().y, material->getKs().z);
	glUniform1f(this->getshininessLocation(), material->getshininess());
}


