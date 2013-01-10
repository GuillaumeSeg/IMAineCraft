#ifndef _COLLINE__HPP
#define _COLLINE__HPP

#include "../../xml/Univers.hpp"

class Colline {

	private:
	int largeur;
	int longueur;
	char type[4];
	int x;
	int y;
	int z;
	
	public:
	Colline(int largeur, int longueur, const char* type, int x, int y, int z, Univers &univ);
	~Colline(){};
	void initCubesColline (Univers &univ);
	void initLayer (Univers &univ, int numLayer, int largeurLayer, int longeurLayer);
};

#endif

