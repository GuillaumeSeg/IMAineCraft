#include <iostream>
#include <list>
#include <algorithm>

#include "../../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../../include/xml/Univers.hpp"
#include "../../include/xml/parser.hpp"

using namespace std;
using namespace imac2gl3;

Univers::Univers() {
	recupererXML(this);
	InitBase();
}

Univers::~Univers() {

	//for_each(AllCube.begin(), AllCube.end(), Delete());
}

void Univers::PushCube(int x, int y, int z)
{
	cout << AllCube.size() << endl;
	// S'il y a déjà un cube à ces coordonnées, on ne crée pas de nouveau cube.
	if (thereIsACubeHere (x, y, z) || isOutOfUniverse (x, y, z))
		return;

	Cube cube(1.f);

	GLShapeInstance cubeinstance (cube);

	cubeinstance.x = x;
	cubeinstance.y = y;
	cubeinstance.z = z;

	AllCube.push_back(cubeinstance);
}

bool Univers::thereIsACubeHere (int x, int y, int z)
{
	list<GLShapeInstance>::iterator it;
	for (it = AllCube.begin(); it != AllCube.end(); it++)
	{
		if ((*it).x == x && (*it).y == y && (*it).z == z)
		{
			return true;
		}
	}
	return false;
}

bool Univers::isOutOfUniverse (int x, int y, int z)
{
	if (x > largeurMax/2 - 1 || x < -largeurMax/2 || y > hauteurMax/2 - 1 || y < -hauteurMax/2 || z > longueurMax/2 - 1 || z < -longueurMax/2)
	{
		return true;
	}
	return false;
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
