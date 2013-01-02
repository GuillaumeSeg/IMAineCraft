#include <iostream>
#include <cstdlib>

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "imac2gl3/shader_tools.hpp"
#include "imac2gl3/shapes/Cube.hpp"
#include "../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../include/imac2gl3/MatrixStack.hpp"
#include "../include/imac2gl3/cameras/FreeFlyCamera.hpp"
#include "../include/imac2gl3/cameras/TrackBallCamera.hpp"

#define FRAME_RATE 60

static const Uint32 MIN_LOOP_TIME = 1000/FRAME_RATE;
static const size_t WINDOW_WIDTH = 512, WINDOW_HEIGHT = 512;
static const size_t BYTES_PER_PIXEL = 32;

int main(int argc, char** argv) {
	
    /********************************************************************
     * INITIALISATION DU PROGRAMME
     ********************************************************************/
    
   bool front = false;
	bool back = false;
	bool left = false;
	bool right = false;
    
    // Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    // Creation de la fenêtre et d'un contexte OpenGL
    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BYTES_PER_PIXEL, SDL_OPENGL);
    
    SDL_WarpMouse(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    
    // Initialisation de GLEW
    GLenum error;
    if(GLEW_OK != (error = glewInit())) {
        std::cerr << "Impossible d'initialiser GLEW: " << glewGetErrorString(error) << std::endl;
        return EXIT_FAILURE;
    }
    
    // Creation des ressources OpenGL
    
    /** PLACEZ VOTRE CODE DE CREATION DES VBOS/VAOS/SHADERS/... ICI **/
    imac2gl3::Cube bloc(1.f);
    imac2gl3::GLShapeInstance bloc1(bloc);
  	 
    GLuint program = imac2gl3::loadProgram("shaders/transform.vs.glsl", "shaders/normalcolor.fs.glsl");
    if(!program){
    	return (EXIT_FAILURE);
    }
    glUseProgram(program);
    
    //MATRIX
    GLint MVPLocation = glGetUniformLocation(program, "uMVPMatrix");
    
    glm::mat4 P = glm::perspective(70.f, WINDOW_WIDTH / (float) WINDOW_HEIGHT, 0.1f, 1000.f);
    glm::mat4 V = glm::lookAt(glm::vec3(0.f,0.f,0.f), glm::vec3(0.f, 0.f, -1.f), glm::vec3(0.f,1.f,0.f));
    glm::mat4 VP = P*V;
    
    imac2gl3::MatrixStack ms;
    ms.set(VP);
    
    imac2gl3::FreeFlyCamera regard;
    imac2gl3::FreeFlyCamera oeil;
    oeil.moveFront(-5);
    
    glEnable(GL_DEPTH_TEST);
    
    //VARIABLE DE MOUVEMENT
    float alpha_earth = 0;
    
    // Boucle principale
    bool done = false;
    while(!done) {
    		// Initilisation compteur
    		Uint32 start = 0;
			Uint32 end = 0;
			Uint32 ellapsedTime = 0;
     	  	start = SDL_GetTicks();
    
        // Nettoyage de la fenêtre
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //Pre-idle
        
        // Dessin
        
        /** PLACEZ VOTRE CODE DE DESSIN ICI **/  
       	ms.push();
       	ms.mult(regard.getViewMatrix());
       	ms.push();
       	if(front) {
        		oeil.moveFront(0.1);
        	}
        	if(back) {
        		oeil.moveFront(-0.1);
        	}
        	if(left) {
        		oeil.rotateLeft(0.5);
        	}
        	if(right) {
        		oeil.rotateLeft(-0.5);
        	}
      	ms.mult(oeil.getViewMatrix());
			
			ms.push();
			
			glUniformMatrix4fv(MVPLocation, 1, GL_FALSE, glm::value_ptr(ms.top()));
			bloc1.draw();
        ms.pop();
        ms.pop();
        ms.pop();
        
        
        
        // Mise à jour de l'affichage
        SDL_GL_SwapBuffers();
        
        // Boucle de gestion des évenements
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
        		if(e.type == SDL_MOUSEMOTION) {
		      		
		       		std::cout << (float)e.motion.xrel << std::endl;
		       		regard.rotateLeft(-(float)e.motion.xrel*0.05);
		       		regard.rotateUp(-(float)e.motion.yrel*0.05);
        		}
		      
		      if(e.type == SDL_KEYDOWN) {
		      	if(e.key.keysym.sym == SDLK_z) {
		      		front = true;
		      	}
		      	if(e.key.keysym.sym == SDLK_s) {
		      		back = true;
		      	}
		      	if(e.key.keysym.sym == SDLK_d) {
		      		right = true;
		      	}
		      	if(e.key.keysym.sym == SDLK_q) {
		      		left = true;
		      	}
		      }
		      if(e.type == SDL_KEYUP) {
		      	if(e.key.keysym.sym == SDLK_z) {
		      		front = false;
		      	}
		      	if(e.key.keysym.sym == SDLK_s) {
		      		back = false;
		      	}
		      	if(e.key.keysym.sym == SDLK_d) {
		      		right = false;
		      	}
		      	if(e.key.keysym.sym == SDLK_q) {
		      		left = false;
		      	}
		      }
            // Traitement de l'évenement fermeture de fenêtre
            if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                done = true;
                break;
            }
            
            // Traitement des autres évenements:
            
            /** PLACEZ VOTRE CODE DE TRAITEMENT DES EVENTS ICI **/
        }
        
        //idle
        alpha_earth +=0.5;
        
        
        	// Gestion compteur
        	end = SDL_GetTicks();
        	ellapsedTime = end - start;
        	if(ellapsedTime < MIN_LOOP_TIME){
				SDL_Delay(MIN_LOOP_TIME - ellapsedTime);
			}
    }
    
    // Destruction des ressources OpenGL
    
    /** PLACEZ VOTRE CODE DE DESTRUCTION DES VBOS/VAOS/SHADERS/... ICI **/
    
    
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
