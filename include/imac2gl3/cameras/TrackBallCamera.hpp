#ifndef IMAC2GL3_TRACKBALLCAMERA_HPP_
#define IMAC2GL3_TRACKBALLCAMERA_HPP_

#include "../shapes/common.hpp"

namespace imac2gl3 {

class TrackBallCamera {
	
	private:
		float m_fDistance;
		float m_fAngleX;
		float m_fAngleY;
		
	public:
		TrackBallCamera() {
			m_fDistance = 0;
			m_fAngleX = 0;
			m_fAngleY = 0;
		}
		
		void moveFront(float distance);
		
		void rotateLeft(float degrees);
		
		void rotateUp(float degrees);
		
		glm::mat4 getViewMatrix() const;
};

}

#endif
