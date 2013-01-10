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

class Univers{

	private:
		int longueurMax;
		int hauteurMax;
		int largeurMax;
		std::list<GLShapeInstance> AllCube;
	
		void InitBase();
		
	public:
		void PushCube(int x, int y, int z);
		/*void MergeList(std::list<imac2gl3::GLShapeInstance> instance) {
			AllCube.merge(instance);
		}*/
		std::list<imac2gl3::GLShapeInstance>* getList(){
			return &AllCube;
		}

		bool thereIsACubeHere (int x, int y, int z);
		bool isOutOfUniverse (int x, int y, int z);
		
		void setlargeurmax(int a) {
			largeurMax = a;
		}
		void setlongeurmax(int a) {
			longueurMax = a;
		}
		void sethauteurmax(int a) {
			hauteurMax = a;
		}
		Univers();
		~Univers();

};

#endif
