#include "Shape.hpp"

Shape::Shape(std::vector<GLfloat> vertexs, std::vector<GLfloat> colors) :
vertexs(new GLfloat[vertexs.size()]), colors(new GLfloat[colors.size()])
{
	for (int i = 0; i < vertexs.size(); i++) this->vertexs[i] = vertexs[i];
	for (int i = 0; i < colors.size(); i++) this->colors[i] = colors[i];
	
	this->bindAttributes();
}

Shape::~Shape()
{
	delete this->vertexs;
	delete this->colors;
}

void Shape::bindAttributes()
{
	glGenVertexArrays(1, &this->attrsList);
	glGenBuffers(1, &this->VBO);
	glBindVertexArray(this->attrsList);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexs), this->vertexs, GL_DYNAMIC_DRAW);
}
