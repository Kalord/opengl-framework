#pragma once

#include <vector>

#include "../core/OpenGL.hpp"
#include "../core/Drawable.hpp"

namespace GL
{
	class Shape : public Drawable
	{
	private:
		/**
		 * Vertexs of the shape
		 */
		GLfloat* vertexs;
		/**
		 * Number of vertices
		 */
		GLint numberVertexs;
		/**
		 * Vertex buffer object
		 */
		GLuint VBO;
		/**
		 * Attributes for shaders
		 */
		GLuint attrsList;

		bool color = false;
	public:
		Shape(std::vector<GLfloat> vertexs, std::vector<GLfloat> colors = {});
		virtual ~Shape();

		void loadVertexs(std::vector<GLfloat> vertexs, std::vector<GLfloat> colors = {});

		/**
		 * Bind VBO and VAO
		 */
		void bindAttributes();

		bool hasColor();

		GLint getNumberVertexs() override;
		void setNumberVertexs(GLint value) override;

		GLuint getAttrsList() override;
	};
}