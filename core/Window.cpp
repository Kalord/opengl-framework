#include "Window.hpp"

GL::Window::Window(uint32_t width, uint32_t height, const std::string& title)
{
	this->window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(this->window);

	glViewport(0, 0, width, height);
}

bool GL::Window::isOpen()
{
	return !glfwWindowShouldClose(this->window);
}

void GL::Window::display()
{
	if (this->issetBackgroundColor())
	{
		glClearColor(
			this->RGBA[RED],
			this->RGBA[GREEN],
			this->RGBA[BLUE],
			this->RGBA[OPACITY]
		);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glfwSwapBuffers(this->window);
}

void GL::Window::setBackgroundColor(GLfloat R, GLfloat G, GLfloat B, GLfloat A)
{
	this->RGBA = { R, G, B, A };
}

bool GL::Window::issetBackgroundColor()
{
	return this->RGBA.size() == 4;
}

void GL::Window::draw(Drawable* drawable)
{
	glBindVertexArray(drawable->getAttrsList());
	glDrawArrays(GL_TRIANGLES, 0, drawable->getNumberVertexs());
	glBindVertexArray(0);
}
