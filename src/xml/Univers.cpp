#include <iostream>
#include <list>
#include <algorithm>

#include "../../include/xml/Univers.hpp"
#include "../../include/xml/parser.hpp"

using namespace std;

Univers::Univers() {
	
	recupererXML(&AllCube, &hauteurMax, &largeurMax, &longueurMax);
}

Univers::~Univers() {

	//for_each(AllCube.begin(), AllCube.end(), Delete());
}

