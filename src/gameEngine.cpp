#include "../include/gameEngine.hpp"
#include "../include/imac2gl3/lighting/Material.hpp"
#include <list>
#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

#define FRAME_RATE 60

using namespace glm;
using namespace std;
using namespace imac2gl3;

static const Uint32 MIN_LOOP_TIME = 1000/FRAME_RATE;
static const size_t WINDOW_WIDTH = 512, WINDOW_HEIGHT = 512;
static const size_t BYTES_PER_PIXEL = 32;

gameEngine::gameEngine(graphicRenderer* renderer){

	gRenderer = renderer;
	
	initSDL();
	// Initialisation de GLEW
    GLenum error;
    if(GLEW_OK != (error = glewInit())) {
        std::cerr << "Impossible d'initialiser GLEW: " << glewGetErrorString(error) << std::endl;
        exit(1);
    }
	univers = new Univers;
}

void gameEngine::initSDL(){
	SDL_Init(SDL_INIT_VIDEO);
	
	// Creation de la fenêtre et d'un contexte OpenGL
    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BYTES_PER_PIXEL, SDL_OPENGL);
    SDL_WarpMouse(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
}

void gameEngine::initCamera(FreeFlyCamera& camera, int position){
    camera.moveFront(float (position), *univers);
}

void gameEngine::run(){
	
	//Création camera + initialisation
	FreeFlyCamera regard;
    	FreeFlyCamera oeil;
	initCamera(oeil,-5);

	//Initialisation mouvement camera
	bool front = false;
	bool back = false;
	bool left = false;
	bool right = false;
	
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
 	  	
 	  	//MATRIX 
		GLuint program = loadProgram("shaders/transform.vs.glsl", "shaders/normalcolor.fs.glsl");
		if(!program){
			exit(1);
		}
		glUseProgram(program);
		
		GLint MVPLocation = glGetUniformLocation(program, "uMVPMatrix");
		
		
		Material matrouge(glm::vec3(15.f,1.f,1.f), glm::vec3(0.f,20.f,1.f), glm::vec3(0.f,0.f,1.f), 1.1);
		Material matbleu(glm::vec3(0.f,0.f,1.f), glm::vec3(0.f,0.f,1.f), glm::vec3(0.f,0.f,1.f), 1.1);
	
		MaterialUniform matuniformrouge;
		MaterialUniform matuniformbleu;
	
		matuniformrouge.getLocations("uMaterial", program);
		
		matuniformrouge.sendMaterial( &matrouge);
		
		// Nettoyage de la fenêtre
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//rendu de l'univers
		gRenderer->renderUniverse(oeil,regard,univers,MVPLocation);
		
        
        
        //Pre-idle
        
        // Dessin
        
        /** PLACEZ VOTRE CODE DE DESSIN ICI **/  
       	
       	if(front) {
        		oeil.moveFront(0.1, *univers);
        	}
        	if(back) {
        		oeil.moveFront(-0.1, *univers);
        	}
        	if(left) {
        		oeil.rotateLeft(0.5);
        	}
        	if(right) {
        		oeil.rotateLeft(-0.5);
        	}
      	
        
        
        // Mise à jour de l'affichage
        SDL_GL_SwapBuffers();
        
        // Boucle de gestion des évenements
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
        		if(e.type == SDL_MOUSEMOTION) {
		      		
		       		//std::cout << (float)e.motion.xrel << std::endl;
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
    
    //LIBERATION DES RESSOURCES
	delete univers;
	SDL_Quit();
    
}
