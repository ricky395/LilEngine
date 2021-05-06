
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#ifndef WINDOW_HEADER
#define WINDOW_HEADER

extern "C"
{
	#include <SDL.h>
}

union SDL_Event;
struct SDL_Window;

/// Clase ventana de SDL

class Window
{

private:

	/// Referencia a la ventana

	SDL_Window * window;
	
	/// Contexto gráfico

	SDL_GLContext gl_context;

public:

	/// Constructor
	/// param title titulo de la ventana a crear
	/// param width ancho de la ventana
	/// param height alto de la ventana

	Window(const char * title, int width, int height);

	/// Destructor

	~Window();

	/// Cierra la ventana

	void close();
	
	/// Ventana a pantalla completa
	/// param state activa o desactiva la pantalla completa

	void set_fullscreen(bool state);
	
	/// Establece el tamaño de ventana
	/// param width ancho
	/// param heigth alto

	void set_size(int width, int height);

	/// Establece el título de la ventana
	/// param title nuevo título

	void set_title(const char* title);
	
	/// Intercambia los buffers de pintado

	void swap_buffers();

};

#endif