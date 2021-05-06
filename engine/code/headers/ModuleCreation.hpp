
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#ifndef MODULE_CREATION_HEADER
#define MODULE_CREATION_HEADER

#include <map>
#include <string>
#include <memory>

#include "Module.hpp"

using namespace std;

/// Factoría de creación de módulos

class ModuleCreation
{

private:

	typedef shared_ptr< Module >(*Module_Factory) (Scene *);
	
	/// Módulos existentes

	std::map< string, Module_Factory > modules;

	/// Referencia a la propia clase

	static ModuleCreation * instance;

private:

	/// Constructor

	ModuleCreation();

	/// Constructor

	ModuleCreation(const ModuleCreation &) 
	{
	}

	ModuleCreation & operator = (const ModuleCreation &) 
	{ 
		return *this; 
	}

public:

	/// Destructor

	~ModuleCreation()
	{
		modules.clear();
	}

	/// Devuelve la instancia a la clase

	static ModuleCreation * Instance()
	{
		if (!instance)
		{
			instance = new ModuleCreation;
		}
		return instance;
	}

	/// Almacena un nuevo módulo
	/// param name nombre del módulo
	/// param factory callback del módulo

	void reg(const string & name, Module_Factory factory)
	{
		modules[name] = factory;
	}

	/// Crea un nuevo módulo

	shared_ptr<Module> createModule(const string & name, Scene * scene);

};

#endif