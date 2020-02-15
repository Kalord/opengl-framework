#pragma once

#include "OpenGL.hpp"

/**
 * This interface is implemented by those classes that should be drawn
 */
class Drawable
{
public:
	virtual ~Drawable() {}

	virtual GLint getNumberVertexs() = 0;
	virtual void setNumberVertexs(GLint value) = 0;

	virtual GLuint getAttrsList() = 0;
};