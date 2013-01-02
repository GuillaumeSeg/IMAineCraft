#include "imac2gl3/cameras/FreeFlyCamera.hpp"

#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



namespace imac2gl3 {


	void FreeFlyCamera::computeDirectionVectors() {
		m_FrontVector = glm::vec3(glm::cos(m_fTheta) * glm::sin(m_fPhi),glm::sin(m_fTheta),glm::cos(m_fTheta) * glm::cos(m_fPhi));
		m_LeftVector = glm::vec3(glm::sin(m_fPhi + (PI / 2)), 0.f, glm::cos(m_fPhi + (PI / 2)));
		m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
	}

	FreeFlyCamera::FreeFlyCamera() {
		m_Position = glm::vec3(0., 0., 0.);
		m_fPhi = PI;
		m_fTheta = 0;
		computeDirectionVectors();
	}

	void FreeFlyCamera::moveLeft(float t) {
		m_Position += m_LeftVector*t;
	}

	void FreeFlyCamera::moveFront(float t) {
		m_Position += m_FrontVector*t;
	}

	void FreeFlyCamera::rotateLeft(float degrees) {
		m_fPhi = m_fPhi + glm::radians(degrees);
		computeDirectionVectors();
	}

	void FreeFlyCamera::rotateUp(float degrees) {
		m_fTheta = m_fTheta + glm::radians(degrees);
		computeDirectionVectors();
	}

	glm::mat4 FreeFlyCamera::getViewMatrix() const {
		//glm::vec3 V = glm::vec3(m_Position.x + m_FrontVector.x, m_Position.y + m_FrontVector.y, m_Position.z + m_FrontVector.z);
		return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
	}
}
