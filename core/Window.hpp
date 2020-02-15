#pragma once

#include <string>
#include <vector>
#include <sys/types.h>

#include "OpenGL.hpp"
#include "Drawable.hpp"

#define RED 0
#define GREEN 1
#define BLUE 2
#define OPACITY 3

namespace GL
{
	/**
	 * The class for work with a window
	 *
	 * If you need to create a window 800x600:
	 *		GL::Window window(800, 600, "Title");
	 * For render:
	 *		while(window.isOpen())
	 *		{
	 *			window.display();	
	 *		}
	 */
	class Window
	{
	private:
		GLFWwindow* window;
		std::vector<int> draws;
		std::vector<GLfloat> RGBA;
	public:
		Window(uint32_t width, uint32_t height, const std::string& title);
		bool isOpen();
		/**
		 * Render the window
		 * This method draw
		 * This method draw objects from property draws
		 */
		void display();

		void setBackgroundColor(GLfloat R, GLfloat G, GLfloat B, GLfloat A);
		bool issetBackgroundColor();

		void draw(Drawable* drawable);
	};
}