#include "../include/texture/Texture.hpp"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/glew.h>
#include <string>

Texture::Texture(std::string name, std::string url)
{
	nom = name;
	path = url;
}


std::string Texture::getNom()
{
    return this->nom;
}

std::string Texture::getPath()
{
    return this->path;
}

void Texture::textureLoad()
{
    SDL_Surface *texImg;
    texImg = IMG_Load(path.c_str()); // permet de convertir le string en *char
	if(!texImg){
		std::cout << "Impossible de charger l'image de texture" << std::endl;
	}
}

void Texture::createTexture(SDL_Surface *objet)
{
    /* CREATION D'UN OBJET TEXTURE */
    GLuint texture;
	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	//récupération du format de l'image
	GLenum format;
		std::cout << objet->format->BytesPerPixel << std::endl;
	switch(objet->format->BytesPerPixel)
	{
		case 1:
			format = GL_RED;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
	}
    
    //Envoi de l'image sur le GPU :
    glTexImage2D(GL_TEXTURE_2D, //target
    	0, //niveau de résolutin quand on utilise le mipmapping
    	GL_RGBA, //format à utiliser sur la carte graphique
    	objet->w, //largeur de l'image
    	objet->h, //hauteur de l'image
    	0, //bordure
    	format, 
    	GL_UNSIGNED_BYTE, //type de données envoyées
    	objet->pixels //pointeur vers les données
    );
    
    //Activation des méthodes de filtrage 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  
    glBindTexture(GL_TEXTURE_2D, 0);
}
