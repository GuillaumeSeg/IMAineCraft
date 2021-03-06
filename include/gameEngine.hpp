#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "graphicRenderer.hpp"

#include "imac2gl3/cameras/FreeFlyCamera.hpp"
#include "imac2gl3/shader_tools.hpp"
#include "imac2gl3/shapes/Cube.hpp"
#include "../include/xml/Univers.hpp"
#include "../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../include/imac2gl3/MatrixStack.hpp"
#include "../include/imac2gl3/cameras/TrackBallCamera.hpp"


class graphicRenderer;
class gameEngine
{
	public :
		graphicRenderer* gRenderer;
		Univers* univers;
	
		//methode
		gameEngine(graphicRenderer* renderer);
		~gameEngine(){} 
		/*void affectUnivers();*/
		void run();
		void initSDL();
		void initGlew();
		void initCamera(imac2gl3::FreeFlyCamera& camera, int position);
};

#endif
