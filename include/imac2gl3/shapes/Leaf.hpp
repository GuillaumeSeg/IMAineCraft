#ifndef _LEAF_
#define _LEAF_

#include "Cube.hpp"

namespace imac2gl3{
	class Leaf : public Cube
	{
	  bool destructible;
	  int const tempsDestruction;
	
		public :
			Leaf (GLfloat size);
	};
}

#endif
