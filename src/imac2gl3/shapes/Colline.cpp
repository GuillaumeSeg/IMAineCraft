#include <cstring>
#include "../../../include/imac2gl3/shapes/Colline.hpp"
#include "../../../include/xml/Univers.hpp"
#include "../../../include/imac2gl3/shapes/Cube.hpp"
#include <iostream>

using namespace std;

Colline::Colline(int largeur, int longueur, const char* type, int x, int y, int z, Univers &univ) {
	this->largeur = largeur;
	this->longueur = longueur;
	strcpy(this->type, type);
	this->x = x;
	this->y = y;
	this->z = z;
	
	initCubesColline(univ);	
}

void Colline::initCubesColline (Univers &univ)
{	
	
	int largeurLayer = this->largeur;
	int longueurLayer = this->longueur;
	int compteurLayer = 0;
	while (largeurLayer > 0 && longueurLayer > 0)
	{
		initLayer (univ, compteurLayer, largeurLayer, longueurLayer);
		compteurLayer ++;
		largeurLayer -= 2;
		longueurLayer -= 2;
	}
}

// La colline est faite de plusieurs layers de cubes
void Colline::initLayer (Univers &univ, int numLayer, int largeurLayer, int longueurLayer)
{	
	
	int i =0;
	int j =0;
	int x = 0, y = 0, z = 0;
	imac2gl3::Cube cube(1.f);
	if (strcmp(type,"pyr")==0 || largeurLayer <= 2)
	{
		for(i = -largeurLayer/2; i < largeurLayer/2; ++i) {
			for( j = -longueurLayer/2; j < longueurLayer/2; ++j) {
					
				x = i + this->x;
				y = numLayer + this->y;
				z = j + this->z;

				univ.PushCube(x, y, z);
			}
		}
	}
	else
	{
		for( i = -largeurLayer/2 + 1; i < largeurLayer/2 - 1; ++i) {
			for( j = -longueurLayer/2; j < longueurLayer/2; ++j) {
			
				x = i + this->x;
				y = numLayer + this->y;
				z = j + this->z;

				univ.PushCube(x, y, z);
			}
		}
		for( j = -longueurLayer/2 + 1; j < longueurLayer/2 - 1; ++j) {
			for ( i = -largeurLayer/2; i < largeurLayer/2; i = i + largeurLayer - 1) {
	
				x = i + this->x;
				y = numLayer + this->y;
				z = j + this->z;

				univ.PushCube(x, y, z);
			}
		}
	}
}
