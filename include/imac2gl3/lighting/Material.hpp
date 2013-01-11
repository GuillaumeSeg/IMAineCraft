#ifndef MATERIAL__HPP
#define MATERIAL__HPP

#include <GL/glew.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Material {

	private:
	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ks;
	float shininess;

	public:
	
	Material(glm::vec3 _ka, glm::vec3 _kd, glm::vec3 _ks, float _shininess);
	~Material(){};
	glm::vec3 getKa();
	glm::vec3 getKd();
	glm::vec3 getKs();
	float getshininess();

};

class MaterialUniform {
	
	private:
	GLint KaLocation;
	GLint KdLocation;
	GLint KsLocation;
	GLint shininessLocation;
	
	public:
	GLint getKaLocation();
	GLint getKdLocation();
	GLint getKsLocation();
	GLint getshininessLocation();
	
	void getLocations(const char* uniform, GLuint program);
	void sendMaterial( Material* material);
};

#endif
