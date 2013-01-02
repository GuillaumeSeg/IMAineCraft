#include <GL/glew.h>
#include "imac2gl3/shapes/common.hpp"
#include "imac2gl3/shapes/GLShapeInstance.hpp"
#include "imac2gl3/shapes/Cube.hpp"

namespace imac2gl3 {

void GLShapeInstance::draw()
{
		glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES,0,vertexCount);
		glBindVertexArray(0);
}
}
