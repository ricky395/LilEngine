
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#ifndef SCENE_HEADER
#define SCENE_HEADER

#include <string>
#include <memory>
#include <map>

#include "Window.hpp"
#include "Kernel.hpp"
#include "Module.hpp"
#include "Dispatcher.hpp"


class Entity;

using namespace std;

/// Clase que maneja todos los objetos de una escena

class Scene
{
	/// Módulos de la escena

	map< string, shared_ptr< Module > > modules;

	/// Entidades de la escena

	map< string, shared_ptr< Entity > > entities;

	/// Referencia al dispatcher

	//Dispatcher * dispatcher;
	
	/// Referencia al kernel
	
	Kernel * kernel;
	
	/// Referencia a la ventana
	
	Window * window;
	
	/// Flag de carga de la escena

	bool loaded;

public:

	/// Constructor
	/// param window referencia a la ventana
	
	Scene(Window * window);

	~Scene()
	{
		kernel->stop();
	}

	/// Devuelve una referencia a la ventana

	inline Window * get_window()
	{
		return window;
	}

	/// Devuelve una referencia al kernel

	inline Kernel * get_kernel()
	{
		return kernel;
	}

	/// Devuelve una referencia al dispatcher de mensajes

	/*inline Dispatcher * get_dispatcher()
	{
		return dispatcher;
	}*/

private:
	
	/// Corre la escena

	inline void run()
	{
		if (loaded)
		{
			kernel->execute();
		}
	}

	/// Inicia la escena

	void init();

	/// Carga la escena

	bool load_scene();

};

#endif