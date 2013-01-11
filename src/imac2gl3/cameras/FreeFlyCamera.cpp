#include "imac2gl3/cameras/FreeFlyCamera.hpp"

#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../../include/xml/Univers.hpp"

#define INITIAL_X 0.0
#define INITIAL_Y 1.0
#define INITIAL_Z 0.0

using namespace glm;

namespace imac2gl3 {


	void FreeFlyCamera::computeDirectionVectors() {
		m_FrontVector = vec3(glm::cos(m_fTheta) * sin(m_fPhi),sin(m_fTheta),cos(m_fTheta) * cos(m_fPhi));
		m_LeftVector = vec3(sin(m_fPhi + (PI / 2)), 0.f, cos(m_fPhi + (PI / 2)));
		m_UpVector = cross(m_FrontVector, m_LeftVector);
	}

	FreeFlyCamera::FreeFlyCamera(Univers univers) {
		float yinit = INITIAL_Y;
		if (univers.thereIsACubeHere (INITIAL_X, yinit - 1., INITIAL_Z))
		{
			yinit += 1.;
		}
		m_Position = vec3(INITIAL_X, yinit, INITIAL_Z);
		m_fPhi = PI;
		m_fTheta = 0;
		computeDirectionVectors();
	}

	vec3 FreeFlyCamera::getFrontVector ()
	{
		return this->m_FrontVector;
	}

	vec3 FreeFlyCamera::getPosition ()
	{
		return this->m_Position;
	}

	void FreeFlyCamera::moveLeft(float t) {
		m_Position += m_LeftVector*t;
	}

	void FreeFlyCamera::moveFront(float t, Univers univers)
	{
		if (collisionCube(t, univers)) { return; }
		if ((t > 0 && canMoveFront(univers)) || (t < 0 && canMoveBack(univers)))
		{
			m_Position += m_FrontVector*t;
			fixGravity (univers);
		}
	}

	bool FreeFlyCamera::canMoveFront (Univers univers)
	{
		/* L'idée, c'est qu'on gère les quatre cas possibles :
			- la caméra se dirige vers les x positifs et les z positifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = largeurMax/2
				z du bord = longueurMax/2
			- la caméra se dirige vers les x positifs et les z négatifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = largeurMax/2
				z du bord = -longueurMax/2
			- la caméra se dirige vers les x négatifs et les z positifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = -largeurMax/2 
				z du bord = longueurMax/2
			- la caméra se dirige vers les x négatifs et les z négatifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = -largeurMax/2
				z du bord = -longueurMax/2
		*/
		if (((m_FrontVector.x > 0 && m_Position.x < univers.getLargeurMax()/2) || (m_FrontVector.x < 0 && m_Position.x > -univers.getLargeurMax()/2)) && ((m_FrontVector.z > 0 && m_Position.z < univers.getLongueurMax()/2) || (m_FrontVector.z < 0 && m_Position.z > -univers.getLongueurMax()/2)))
			return true;

		return false;
	}

	bool FreeFlyCamera::canMoveBack (Univers univers)
	{
		/* L'idée, c'est qu'on gère les quatre cas possibles :
			- la caméra se dirige vers les x positifs et les z positifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = -largeurMax/2
				z du bord = -longueurMax/2
			- la caméra se dirige vers les x positifs et les z négatifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = -largeurMax/2
				z du bord = longueurMax/2
			- la caméra se dirige vers les x négatifs et les z positifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = largeurMax/2 
				z du bord = -longueurMax/2
			- la caméra se dirige vers les x négatifs et les z négatifs : alors on doit s'arrêter de bouger avant que la position de la caméra soit trop près du bord, c'est à dire :
				x du bord = largeurMax/2
				z du bord = longueurMax/2
		*/
		if (((m_FrontVector.x < 0 && m_Position.x < univers.getLargeurMax()/2) || (m_FrontVector.x > 0 && m_Position.x > -univers.getLargeurMax()/2)) && ((m_FrontVector.z < 0 && m_Position.z < univers.getLongueurMax()/2) || (m_FrontVector.z > 0 && m_Position.z > -univers.getLongueurMax()/2)))
			return true;

		return false;
	}

	void FreeFlyCamera::fixGravity (Univers univers)
	{
		if (!univers.gravityCheck (m_Position.x, m_Position.y, m_Position.z - 5.))
		{
			float new_y = m_Position.y - 1.;
			while (m_Position.y >= new_y + 0.0001)
			{
				m_Position.y -= 0.0001;
			}
		}
	}

	bool FreeFlyCamera::collisionCube (float t, Univers univers)
	{
		vec3 testPosition = m_Position + m_FrontVector*t;
		return univers.youAreInsideACube (testPosition.x, testPosition.y, testPosition.z);
	}

	void FreeFlyCamera::rotateLeft(float degrees) {
		m_fPhi = m_fPhi + radians(degrees);
		computeDirectionVectors();
	}

	void FreeFlyCamera::rotateUp(float degrees) {
		m_fTheta = m_fTheta + radians(degrees);
		computeDirectionVectors();
	}

	mat4 FreeFlyCamera::getViewMatrix() const {
		//glm::vec3 V = glm::vec3(m_Position.x + m_FrontVector.x, m_Position.y + m_FrontVector.y, m_Position.z + m_FrontVector.z);
		return lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
	}
}
