#include <iostream>
#include <cstdlib>
#include <list>
#include "../../include/imac2gl3/shapes/Cube.hpp"
#include "../../include/imac2gl3/shapes/GLShapeInstance.hpp"
#include "../../include/xml/tinyxml.h"
#include "../../include/xml/parser.hpp"
#include "../../include/imac2gl3/shapes/Colline.hpp"
#include "../../include/xml/Univers.hpp"

using namespace std;
using namespace imac2gl3;

void recupererXML(Univers *univ) {
	
	TiXmlDocument doc("data/univers.xml");
	if(!doc.LoadFile()){
	   	cerr << "erreur lors du chargement" << endl;
	   	cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
	   	exit(1);
	}
	
	TiXmlHandle hdl(&doc);
	TiXmlElement *elem = hdl.FirstChildElement().Element();
	
	int a,b,c;
	elem->QueryIntAttribute("largeurMax", &a);
	elem->QueryIntAttribute("longueurMax", &b);
	elem->QueryIntAttribute("hauteurMax", &c);
	(*univ).setlargeurmax(a);
	(*univ).setlongeurmax(b);
	(*univ).sethauteurmax(c);
	
	elem = hdl.FirstChildElement("univers").FirstChildElement().Element();
	
	
	list<GLShapeInstance>::iterator i;
	
	Cube cube(1.f);
	if(!elem){
		cerr << "le noeud à atteindre n'existe pas" << endl;
		exit(1);
	}

	while (elem){
	
		int tmplargeur;
		int tmplongueur;
		int tmpx;
		int tmpy;
		int tmpz;
	
		if (strcmp (elem->Value (), "colline") == 0) {
		
			elem->QueryIntAttribute ("largeur", &tmplargeur);
			elem->QueryIntAttribute ("longueur", &tmplongueur);
			elem->QueryIntAttribute ("x", &tmpx);
			elem->QueryIntAttribute ("y", &tmpy);
			elem->QueryIntAttribute ("z", &tmpz);
		
		
			Colline hill(tmplargeur, tmplongueur, elem->Attribute("type"), tmpx, tmpy, tmpz, *univ);
		}

		if (strcmp (elem->Value (), "cube") == 0) {
		
			elem->QueryIntAttribute ("x", &tmpx);
			elem->QueryIntAttribute ("y", &tmpy);
			elem->QueryIntAttribute ("z", &tmpz);
			univ->PushCube (tmpx, tmpy, tmpz);
	
		}
	
		elem = elem->NextSiblingElement(); // iteration 
	}
}


