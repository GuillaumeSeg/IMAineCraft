#ifndef _IMAC2GL3_GLShapeInstance_HPP_
#define _IMAC2GL3_GLShapeInstance_HPP_

#include <iostream>
#include <string>
#include "imac2gl3/shapes/Cube.hpp"
#include "common.hpp"

namespace imac2gl3 {

class GLShapeInstance {
	
	public:
		GLuint VBO;
		GLuint VAO;
		GLsizei vertexCount;
		int x, y, z;
		std::string type;
		
		template<typename Shape>
		GLShapeInstance(const Shape& sphere) {
			vertexCount = sphere.getVertexCount();
	
			glGenBuffers(1, &VBO);
			 
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sphere.getByteSize(), sphere.getDataPointer(), GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER,0); //Débind du VBO
    
			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
		
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glVertexAttribPointer(
				0,
				sphere.getPositionNumComponents(),
		   		sphere.getDataType(),
				GL_FALSE,
	  			sphere.getVertexByteSize(),
	  			sphere.getPositionOffset());
				
			glVertexAttribPointer(
				1,
				sphere.getNormalNumComponents(),
				sphere.getDataType(),
				GL_FALSE,
				sphere.getVertexByteSize(),
				sphere.getNormalOffset()
			);
    		
    		glVertexAttribPointer(
    			2,
    			sphere.getTexCoordsNumComponents(),
    			sphere.getDataType(),
    			GL_FALSE,
    			sphere.getVertexByteSize(),
    			sphere.getTexCoordsOffset()
    		);
			glBindBuffer(GL_ARRAY_BUFFER,0); //Débind du VBO
			glBindVertexArray(0); //débind du VAO
		
		}
		
		void draw();
};
}
#endif
