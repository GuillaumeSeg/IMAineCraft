#include <iostream>
#include <list>
#include <algorithm>

#include "../../include/xml/Univers.hpp"
#include "../../include/xml/parser.hpp"

using namespace std;

Univers::Univers() {
	std::cout << "test4" << std::endl;
	recupererXML(&AllCube, &hauteurMax, &largeurMax, &longueurMax);
	std::cout << "test5" << std::endl;
}

Univers::~Univers() {

	//for_each(AllCube.begin(), AllCube.end(), Delete());
}

