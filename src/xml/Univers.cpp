#include <iostream>
#include <list>
#include <algorithm>

#include "../../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../../include/xml/Univers.hpp"
#include "../../include/xml/parser.hpp"

using namespace std;
using namespace imac2gl3;

Univers::Univers() {
	recupererXML(&AllCube, &hauteurMax, &largeurMax, &longueurMax);
	InitBase();
}

Univers::~Univers() {

	//for_each(AllCube.begin(), AllCube.end(), Delete());
}

void Univers::InitBase() {

	for(int i = -largeurMax/2; i < largeurMax/2; ++i){
		for(int j = -longueurMax/2; j < longueurMax/2; ++j) {
		Cube cube(1.f);
		
		GLShapeInstance cubeinstance(cube);
		
		cubeinstance.x = i;
		cubeinstance.y = -hauteurMax/2;
		cubeinstance.z = j;
		
		AllCube.push_back(cubeinstance);
		}
	}
}
