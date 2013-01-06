#ifndef _TERRE_
#define _TERRE_

#include "Cube.hpp"

namespace imac2gl3{
	class Terre : public Cube
	{
	  bool destructible;
	  int const tempsDestruction;
	
		public :
			Terre (GLfloat size);
	};
}

#endif
