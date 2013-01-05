#ifndef _UNIVERS__HPP
#define _UNIVERS__HPP

#include <list>
#include "../imac2gl3/shapes/GLShapeInstance.hpp"


/* Foncteur servant à libérer un pointeur - applicable à n'importe quel type
struct Delete 
{ 
   template <imac2gl3::GLShapeInstance> operator ()(imac2gl3::GLShapeInstance*& p)
   { 
      delete p;
      p = NULL; 
   } 
};*/

class Univers{

	public:
		int longueurMax;
		int hauteurMax;
		int largeurMax;
		std::list<imac2gl3::GLShapeInstance> AllCube;
	
	public:
		Univers();
		~Univers();

};

#endif