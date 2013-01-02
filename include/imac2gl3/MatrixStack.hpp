#ifndef MATRIX_STACK
#define MATRIX_STACK
#include <stack>
#include <iostream>
#include "glm/glm.hpp"

namespace imac2gl3
{

class MatrixStack
{
	private :
		std::stack<glm::mat4> m_Stack;
		
	public :
		MatrixStack();
		void push();
		void pop();
		void mult(const glm::mat4& m);
		const glm::mat4& top() const;
		void set(const glm::mat4& m);
		void scale(const glm::vec3& s);
		void translate(const glm::vec3& t);
		void rotate(float degrees, const glm::vec3& r);
};

}
#endif
