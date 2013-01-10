#ifndef _IMAC2GL3_FreeFlyCamera_HPP_
#define _IMAC2GL3_FreeFlyCamera_HPP_

#include "../shapes/common.hpp"
#include "../../xml/Univers.hpp"

using namespace glm;

namespace imac2gl3 {

class FreeFlyCamera {

private :
	// position de la caméra
	vec3 m_Position;

	// les coord sphériques du vector F
	float m_fPhi;
	float m_fTheta;

	vec3 m_FrontVector; // vector F
	vec3 m_LeftVector; // vector L
	vec3 m_UpVector; // vector U

	void computeDirectionVectors();

public:
	FreeFlyCamera(Univers univers);

	vec3 getFrontVector ();
	vec3 getPosition ();

	bool canMoveFront (Univers univers);
	bool canMoveBack (Univers univers);
	bool collisionCube (float t, Univers univers);

	void moveLeft(float t);
	void moveFront(float t, Univers univers);
	void rotateLeft(float degrees);
	void rotateUp(float degrees);
	mat4 getViewMatrix() const;
};

}

#endif
