#include <iostream>
#include <cstdlib>

#include "../include/gameEngine.hpp"
#include "../include/graphicRenderer.hpp"

int main(int argc, char** argv) {
	
    /********************************************************************
     * INITIALISATION DU PROGRAMME
     ********************************************************************/
    /*
    // Initialisation de GLEW
    GLenum error;
    if(GLEW_OK != (error = glewInit())) {
        std::cerr << "Impossible d'initialiser GLEW: " << glewGetErrorString(error) << std::endl;
        return EXIT_FAILURE;
    }*/
  
    
    
    // Creation des ressources OpenGL
    
    /** PLACEZ VOTRE CODE DE CREATION DES VBOS/VAOS/SHADERS/... ICI **/
     
    
    
    //instanciation moteur graphique
    graphicRenderer gRenderer;
    
    //création instance de jeu 
    gameEngine game(&gRenderer);
    game.run();
    
    // Destruction des ressources OpenGL
    
    /** PLACEZ VOTRE CODE DE DESTRUCTION DES VBOS/VAOS/SHADERS/... ICI **/
    
    
    
    
    return EXIT_SUCCESS;
}
