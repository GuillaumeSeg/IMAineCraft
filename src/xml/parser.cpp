#include <iostream>
#include <list>
#include "../../include/imac2gl3/shapes/Cube.hpp"
#include "../../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../../include/xml/tinyxml.h"
#include "../../include/xml/parser.hpp"

void recupererXML(std::list<imac2gl3::GLShapeInstance> *allcube,int *Hamax,int *Lamax, int *Lomax) {
	using namespace std;
	
	TiXmlDocument doc("data/univers.xml");
	if(!doc.LoadFile()){
   	cerr << "erreur lors du chargement" << endl;
   	cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
   	exit(1);
	}
	
	TiXmlHandle hdl(&doc);
	TiXmlElement *elem = hdl.FirstChildElement().Element();
	
	elem->QueryIntAttribute("largeurMax", Lamax);
	elem->QueryIntAttribute("longueurMax", Lomax);
	elem->QueryIntAttribute("hauteurMax", Hamax);
	
	elem = hdl.FirstChildElement().FirstChildElement().Element();
	
	std::list<imac2gl3::GLShapeInstance>::iterator i;
	
	imac2gl3::Cube cube(1.f);
	if(!elem){
		cerr << "le noeud à atteindre n'existe pas" << endl;
		exit(1);
	}
	 
	while (elem){
	
		imac2gl3::GLShapeInstance cubeinstance(cube);
		elem->QueryIntAttribute("x", &cubeinstance.y);
		elem->QueryIntAttribute("y", &cubeinstance.x);
		elem->QueryIntAttribute("z", &cubeinstance.z);
		(*allcube).push_back(cubeinstance);
		
		
		for(i=allcube->begin(); i!=allcube->end(); i++) {
				std::cout << i->x << "  " << i->y << std::endl;
    		}
	 
		elem = elem->NextSiblingElement(); // iteration 
	}
	
	
}

