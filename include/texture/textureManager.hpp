#ifndef _TEXTURE_MANAGER_
#define _TEXTURE_MANAGER_

#include <vector>
#include <string>
#include "Texture.hpp"

class Texture;
class textureManager
{
    public :
        static textureManager* Instance(); 
        void initTextures(); 
        void addTexture(Texture* texture); //ajouter une texture à la collection
        void deleteTexture(Texture* texture); //supprimer une texture de la collection
        Texture* getTexture(std::string name);

    protected :
        textureManager(){};
        ~textureManager();

    private :
        static textureManager* _instance;
        std::vector<Texture*> collecTextures;
};


#endif

//gestion de l'instanciation des textures en Singleton. On attribue le meme objet texture à chaque objet du meme type texture.
