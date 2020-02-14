#include "Init.hpp"

/**
 * Setup Open GL
 * Set major and minor version
 */
void GL::Init::init(int major, int minor)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glewExperimental = GL_TRUE;
	glewInit();
}

void GL::Init::free()
{
	glfwTerminate();
}
