#ifndef _WATER_
#define _WATER_

#include "Cube.hpp"

namespace imac2gl3{
	class Water : public Cube
	{
	  bool destructible;
	  int const tempsDestruction;
	
		public :
			Water (GLfloat size);
	};
}

#endif
