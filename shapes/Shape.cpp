#include "Shape.hpp"

GL::Shape::Shape(std::vector<GLfloat> vertexs, std::vector<GLfloat> colors) :
vertexs(new GLfloat[vertexs.size() + colors.size()])
{
	this->loadVertexs(vertexs, colors);
	//this->bindAttributes();
}

GL::Shape::~Shape()
{
	delete this->vertexs;
}

void GL::Shape::loadVertexs(std::vector<GLfloat> vertexs, std::vector<GLfloat> colors)
{
	int i = 0;
	while (i < vertexs.size())
	{
		this->vertexs[i] = vertexs[i];
		i++;
	}
	this->setNumberVertexs(vertexs.size() / 3);

	if (colors.size())
	{
		int j = 0;
		while (j < colors.size())
		{
			this->vertexs[i];
			i++;
			j++;
		}
		this->color = true;
	}
}

void GL::Shape::bindAttributes()
{
	glGenVertexArrays(1, &this->attrsList);
	glGenBuffers(1, &this->VBO);
	glBindVertexArray(this->attrsList);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexs), this->vertexs, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

bool GL::Shape::hasColor()
{
	return this->color;
}

GLint GL::Shape::getNumberVertexs()
{
	return this->numberVertexs;
}

void GL::Shape::setNumberVertexs(GLint value)
{
	this->numberVertexs = value;
}

GLuint GL::Shape::getAttrsList()
{
	return this->attrsList;
}
