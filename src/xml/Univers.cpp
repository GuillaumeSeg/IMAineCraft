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

list<GLShapeInstance>* Univers::getList(){
	return &AllCube;
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

bool Univers::youAreInsideACube (int x, int y, int z)
{
	list<GLShapeInstance>::iterator it;
	for (it = AllCube.begin(); it != AllCube.end(); it++)
	{
		cout << x << " ou " << it->x << ", " << endl;
		if (x >= it->x - 0.9 && x <= it->x + 0.9 && z >= it->z - 0.9 && z <= it->z + 0.9 && y >= it->y - 0.9 && y <= it->y + 0.9)
		{
			return true;
		}
	}
	return false;
}

bool Univers::isOutOfUniverse (int x, int y, int z)
{
	if (x > largeurMax/2 - 1 || x < -largeurMax/2 || y < 0. || y > hauteurMax - 1 || z > longueurMax/2 - 1 || z < -longueurMax/2)
	{
		return true;
	}
	return false;
}

bool Univers::isEmpty ()
{
	return AllCube.empty();
}

void Univers::InitBase() {

	for(int i = -largeurMax/2; i < largeurMax/2; ++i){
		for(int j = -longueurMax/2; j < longueurMax/2; ++j) {
			Cube cube(1.f);
		
			GLShapeInstance cubeinstance(cube);
		
			cubeinstance.x = i;
			cubeinstance.y = 0;
			cubeinstance.z = j;
		
			AllCube.push_back(cubeinstance);
		}
	}
}
