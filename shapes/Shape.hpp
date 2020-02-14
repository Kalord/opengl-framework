#pragma once

#include <vector>

#include "../core/OpenGL.hpp"
#include "../core/Drawable.hpp"

class Shape : public Drawable
{
private:
	/**
	 * Vertexs of the shape
	 */
	GLfloat* vertexs;
	/**
	 * Colors of the shape
	 */
	GLfloat* colors;
	/**
	 * Vertex buffer object
	 */
	GLuint VBO;
	/**
	 * Attributes for shaders
	 */
	GLuint attrsList;
public:
	Shape(std::vector<GLfloat> vertexs, std::vector<GLfloat> colors);
	virtual ~Shape();
	/**
	 * Bind VBO and VAO
	 */
	void bindAttributes();
};