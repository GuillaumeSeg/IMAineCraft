#include <iostream>
#include <list>
#include <algorithm>
#include <string>

#include "../../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../../include/xml/Univers.hpp"
#include "../../include/xml/parser.hpp"

#include "../../include/imac2gl3/shapes/Wood.hpp"
#include "../../include/imac2gl3/shapes/Sand.hpp"
#include "../../include/imac2gl3/shapes/Water.hpp"
#include "../../include/imac2gl3/shapes/Stone.hpp"
#include "../../include/imac2gl3/shapes/Torche.hpp"
#include "../../include/imac2gl3/shapes/Terre.hpp"
#include "../../include/imac2gl3/shapes/Leaf.hpp"

using namespace std;
using namespace imac2gl3;

Univers::Univers() {
	recupererXML(this);
	InitBase();
}

Univers::~Univers() {

	//for_each(AllCube.begin(), AllCube.end(), Delete());
}

list<GLShapeInstance>* Univers::getList(){
return &AllCube;
}

void Univers::PushCube(int x, int y, int z, std::string type)
{
	cout << AllCube.size() << endl;
	// S'il y a déjà un cube à ces coordonnées, on ne crée pas de nouveau cube.
	if (thereIsACubeHere (x, y, z) || isOutOfUniverse (x, y, z))
		return;

	Cube cube(1.f);
	/*switch(type)
	{
		case "feuille" :
			Leaf cube(1.f);
			break;
		case "pierre" :
			Stone cube(1.f);
			break;
		case "eau" :
			Water cube(1.f);
			break;
		case "sable" :
			Sand cube(1.f);
			break;
		case "terre" :
			Terre cube(1.f);
			break;
		case "torche" :
			Torche cube(1.f);
			break;
		case "bois" :
			Wood cube(1.f);
			break;
	}*/

	GLShapeInstance cubeinstance(cube);

	cubeinstance.x = x;
	cubeinstance.y = y;
	cubeinstance.z = z;
	cubeinstance.type = type;

	fixCubeGravity (cubeinstance);

	AllCube.push_back(cubeinstance);
}

bool Univers::youAreInsideACube (float x, float y, float z)
{
	list<GLShapeInstance>::iterator it;
	for (it = AllCube.begin(); it != AllCube.end(); it++)
	{
	// cout << x << " ou " << it->x << ", " << y << " ou " << it->y << ", " << z << " ou " << it->z << endl;
	if (x >= it->x - 0.7 && x <= it->x + 0.7 && z >= it->z - 0.7 && z <= it->z + 0.7 && y >= it->y - 0.7 && y <= it->y + 0.7)
	{
	return true;
	}
	}
	return false;
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

bool Univers::gravityCheck (float x, float y, float z)
{
	if (thereIsACubeHere (int(x), int(y) - 1, int(z)) || y == 1.)
	{
		//cout << "im falling : " << x << "," << y << "," << z << endl;
		return true;
	}
	return false;
}

void Univers::fixCubeGravity (GLShapeInstance& cube)
{
	while (!gravityCheck (float(cube.x), float(cube.y), float(cube.z)))
	{
		cube.y -= 1;
	}
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
