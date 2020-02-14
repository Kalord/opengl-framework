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
	glfwSwapBuffers(this->window);
}
