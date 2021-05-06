
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#include <Window.hpp>
#include <iostream>

#include <glbinding\Binding.h>
#include <glbinding\gl\gl.h>

#include "Scene.hpp"

using namespace glbinding;

Window::Window(const char * title, int width, int height)
{
	// Activación del doble buffer de ventana

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Ventana de SDL

	window = SDL_CreateWindow
	(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_OPENGL
	);

	// Contexto de SDL

	gl_context = SDL_GL_CreateContext(window);

	Binding::initialize();
	
	// Se crea la escena

	Scene * scene = new Scene(this);
}

Window::~Window()
{
	close();
}

void Window::close()
{
	SDL_DestroyWindow (window);
}

void Window::set_fullscreen(bool state) 
{
	SDL_SetWindowFullscreen(window, state);		
}

void Window::set_size(int width, int height)
{
	SDL_SetWindowSize(window, width, height);
}

void Window::set_title(const char* title)
{
	SDL_SetWindowTitle(window, title);
}

void Window::swap_buffers()
{
	SDL_GL_SwapWindow(window);
}