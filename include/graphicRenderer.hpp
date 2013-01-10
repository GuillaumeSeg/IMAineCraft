#ifndef _GRAPHIC_RENDERER_
#define _GRAPHIC_RENDERER_

#include "gameEngine.hpp"
#include "xml/Univers.hpp"
#include "../include/imac2gl3/cameras/FreeFlyCamera.hpp"

class graphicRenderer
{	
	friend class gameEngine;
	protected :
		Univers* universe;

	public : 
		graphicRenderer();
		~graphicRenderer(){}
		void renderUniverse(imac2gl3::FreeFlyCamera& camera1, imac2gl3::FreeFlyCamera& camera2, GLint matrix);
		void loadTextureManager(); 
		void setTextures(); //appliquer une texture à un cube suivant le type
};

#endif
