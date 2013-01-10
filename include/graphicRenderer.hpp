#ifndef _GRAPHIC_RENDERER_
#define _GRAPHIC_RENDERER_

#include "gameEngine.hpp"
#include "xml/Univers.hpp"
#include "../include/imac2gl3/cameras/FreeFlyCamera.hpp"

class graphicRenderer
{	
	public : 
		graphicRenderer();
		~graphicRenderer(){}
		void renderUniverse(imac2gl3::FreeFlyCamera& camera1, imac2gl3::FreeFlyCamera& camera2, Univers* universe, GLint matrix);
		void drawShapes(); //prendre formes à dessiner en parametres
		
};

#endif
