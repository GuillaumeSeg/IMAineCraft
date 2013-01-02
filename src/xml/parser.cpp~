#include <iostream>
#include "../../include/xml/tinyxml.h"
#include "../../include/xml/parser.hpp"

void chargementXML() {
	using namespace std;
	
	TiXmlDocument doc("data/univers.xml");
	if(!doc.LoadFile()){
   	cerr << "erreur lors du chargement" << endl;
   	cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
   	exit(1);
	}
}
