#ifndef _SAND_
#define _SAND_

#include "Cube.hpp"

namespace imac2gl3{
	class Sand : public Cube
	{
	  bool destructible;
	  int const tempsDestruction;
	
		public :
			Sand (GLfloat size);
	};
}

#endif
