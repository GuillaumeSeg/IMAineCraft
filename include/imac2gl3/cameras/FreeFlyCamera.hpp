#ifndef _IMAC2GL3_FreeFlyCamera_HPP_
#define _IMAC2GL3_FreeFlyCamera_HPP_

#include "../shapes/common.hpp"

namespace imac2gl3 {

class FreeFlyCamera {

private :
	// position de la caméra
	glm::vec3 m_Position;

	// les coord sphériques du vector F
	float m_fPhi;
	float m_fTheta;

	glm::vec3 m_FrontVector; // vector F
	glm::vec3 m_LeftVector; // vector L
	glm::vec3 m_UpVector; // vector U

	void computeDirectionVectors();

public:
	FreeFlyCamera();
	void moveLeft(float t);
	void moveFront(float t);
	void rotateLeft(float degrees);
	void rotateUp(float degrees);
	glm::mat4 getViewMatrix() const;
};

}

#endif
