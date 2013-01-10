#include "../include/graphicRenderer.hpp"

#define FRAME_RATE 60

typedef unsigned int Uint32;

static const Uint32 MIN_LOOP_TIME = 1000/FRAME_RATE;
static const size_t WINDOW_WIDTH = 512, WINDOW_HEIGHT = 512;
static const size_t BYTES_PER_PIXEL = 32;

graphicRenderer::graphicRenderer()
{
	
}

void graphicRenderer::renderUniverse(imac2gl3::FreeFlyCamera& cameraDirection, imac2gl3::FreeFlyCamera& cameraOrientation, Univers* universe, GLint matrix){

	glm::mat4 P = glm::perspective(70.f, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1f, 1000.f);
	glm::mat4 V = glm::lookAt(glm::vec3(0.f,0.f,0.f), glm::vec3(0.f, 0.f, -1.f), glm::vec3(0.f,1.f,0.f));
	glm::mat4 VP = P*V;
	
	imac2gl3::MatrixStack ms;
	ms.set(VP);
	
	glEnable(GL_DEPTH_TEST);
	
	ms.push();
   	ms.mult(cameraOrientation.getViewMatrix());
   	ms.push();
   	
   	ms.mult(cameraDirection.getViewMatrix());
			
	ms.push();
	
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(ms.top()));
	
	// i : iterator de la liste de cubes
    std::list<imac2gl3::GLShapeInstance>::iterator i;
	for(i=universe->AllCube.begin(); i!=universe->AllCube.end(); ++i) {
		ms.push();
		ms.translate(glm::vec3(i->x,0.0f,0.0f));
		ms.translate(glm::vec3(0.0f,i->y,0.0f));
		ms.translate(glm::vec3(0.0f,0.0f,i->z));
		
		glUniformMatrix4fv(matrix,1,GL_FALSE,glm::value_ptr(ms.top()));
		
		(*i).draw();
		ms.pop();
	}
		
    ms.pop();
    ms.pop();
    ms.pop();
}

void graphicRenderer::drawShapes(){

}
