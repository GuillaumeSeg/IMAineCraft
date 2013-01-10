#include <GL/glew.h>
#include "imac2gl3/shapes/common.hpp"
#include "imac2gl3/shapes/GLShapeInstance.hpp"
#include "imac2gl3/shapes/Cube.hpp"
#include <iostream>

namespace imac2gl3 {

void GLShapeInstance::draw()
{	/*
		//Activation de l'unité de texture et bindage de la texture openGL
		glActiveTexture(GL_TEXTURE0); //unité de texture 0, valeur envoyée pour l'uniforme
		glBindTexture(GL_TEXTURE_2D, texture); //bindage de l'objet openGL "texture" sur la cible GL_TEXTURE_2D de l'unite 0
		*/
		glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES,0,vertexCount);
		glBindVertexArray(0);
}
}
