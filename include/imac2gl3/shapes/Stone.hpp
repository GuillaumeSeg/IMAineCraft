#ifndef _STONE_
#define _STONE_

#include "Cube.hpp"

namespace imac2gl3{
	class Stone : public Cube
	{
	  bool destructible;
	  int const tempsDestruction;
	
		public :
			Stone (GLfloat size);
	};
}

#endif
