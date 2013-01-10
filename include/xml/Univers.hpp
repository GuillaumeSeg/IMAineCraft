#ifndef _UNIVERS__HPP
#define _UNIVERS__HPP

#include <list>
#include "../imac2gl3/shapes/GLShapeInstance.hpp"
#include "../imac2gl3/shapes/Cube.hpp"


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
using namespace std;

class Univers{

	private:
		int longueurMax;
		int hauteurMax;
		int largeurMax;
		list<GLShapeInstance> AllCube;
	
		void InitBase();
		
	public:
		void PushCube(int x, int y, int z);

		list<GLShapeInstance>* getList();

		bool thereIsACubeHere (int x, int y, int z);
		bool youAreInsideACube (float x, float y, float z);
		bool isOutOfUniverse (int x, int y, int z);

		bool isEmpty ();
		
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
