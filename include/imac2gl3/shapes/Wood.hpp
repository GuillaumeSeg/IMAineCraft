#ifndef _WOOD_
#define _WOOD_

#include "Cube.hpp"

namespace imac2gl3{
	class Wood : public Cube
	{
	  bool destructible;
	  int const tempsDestruction;
	
		public :
			Wood (GLfloat size);
	};
}

#endif
