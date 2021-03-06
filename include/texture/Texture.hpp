#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <string>
#include <SDL/SDL.h>
#include "textureManager.hpp"

using namespace std;

class textureManager;
class Texture
{
	friend class textureManager;
    protected :
        std::string nom;
        std::string path;
        
    public :
        Texture(string name, string url);
        ~Texture(){};
        std::string getNom();
        std::string getPath();
        
        //methodes OpenGL
        void textureLoad();
        void createTexture(SDL_Surface *objet);
};


#endif
