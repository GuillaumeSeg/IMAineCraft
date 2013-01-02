#include "../include/imac2gl3/MatrixStack.hpp"
#include <stack>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace imac2gl3
{

MatrixStack::MatrixStack()
{
	m_Stack.push(glm::mat4(1.f));
}

void MatrixStack::push() {
	m_Stack.push(m_Stack.top());
}

void MatrixStack::pop() {
	m_Stack.pop();
}

void MatrixStack::mult(const glm::mat4& m)
{
	m_Stack.top() *= m;
}

const glm::mat4& MatrixStack::top() const
{
	return m_Stack.top();
}

void MatrixStack::set(const glm::mat4& m)
{
	m_Stack.top() = m;
}

void MatrixStack::scale(const glm::vec3& s)
{
	m_Stack.top() = glm::scale(m_Stack.top(), s);
}

void MatrixStack::translate(const glm::vec3& t)
{
	m_Stack.top() = glm::translate(m_Stack.top(), t);
}

void MatrixStack::rotate(float degrees, const glm::vec3& r)
{
	m_Stack.top() = glm::rotate(m_Stack.top(), degrees, r);
}

}
