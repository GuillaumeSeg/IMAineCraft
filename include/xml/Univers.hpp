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

using namespace imac2gl3;

class Univers{

	public:
		int longueurMax;
		int hauteurMax;
		int largeurMax;
		std::list<GLShapeInstance> AllCube;
	
		void InitBase();
		
		void PushCube(GLShapeInstance instance) {
			AllCube.push_back(instance);
		}
		void SpliceList(std::list<GLShapeInstance> instance) {
			AllCube.splice(AllCube.end(), instance);
		}
		
		void setlargeurmax(int a) {
			largeurMax = a;
		}
		void setlongeurmax(int a) {
			longueurMax = a;
		}
		void sethauteurmax(int a) {
			hauteurMax = a;
		}

		int getLargeurMax ()
		{
			return largeurMax;
		}

		int getLongueurMax ()
		{
			return longueurMax;
		}

		int getHauteurMax ()
		{
			return hauteurMax;
		}

		Univers();
		~Univers();

};

#endif
