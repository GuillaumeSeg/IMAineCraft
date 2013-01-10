#include "../include/texture/textureManager.hpp"
#include <string>
#include <vector>

textureManager* textureManager::_instance = 0;

textureManager* textureManager::Instance()
{
    if (_instance == 0){
        _instance = new textureManager;
    }
    return _instance;
}

textureManager::~textureManager()
{
	unsigned int i;
	for(i=0;i<collecTextures.size();++i)
	{
		delete this->collecTextures[i];
	}
	this->collecTextures.clear();
}

void textureManager::addTexture(Texture* texture)
{
	unsigned int i;
	bool existe;

	//on parcourt la collection pour voir si la texture n'y est pas déjà présente
	for(i=0;i<this->collecTextures.size();++i)
	{
		if(this->collecTextures[i]->nom == texture->nom)
		{
			existe = true;
		}
	}
	if(existe == false){
		//ajout texture dans vecteur textures avec push_back
		this->collecTextures.push_back(texture);
	}
}

void textureManager::deleteTexture(Texture* texture)
{
	/*unsigned int i;
	for(i=0;i<this->collecTextures.size();++i)
	{
		if(collecTextures[i]->nom == texture->nom)
		{
			this->collecTextures.erase(collecTextures[i]);
		}
	}*/
}

Texture* textureManager::getTexture(string name)
{
	unsigned int i;
	for(i=0; i<this->collecTextures.size();++i)
	{
		if(collecTextures[i]->nom == name)
		{
			return collecTextures[i];
		}
	}
	return 0;
}
