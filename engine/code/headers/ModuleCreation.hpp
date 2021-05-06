
/// Author: Ricardo Rold�n Fern�ndez
/// Date: 26/06/2018

#ifndef MODULE_CREATION_HEADER
#define MODULE_CREATION_HEADER

#include <map>
#include <string>
#include <memory>

#include "Module.hpp"

using namespace std;

/// Factor�a de creaci�n de m�dulos

class ModuleCreation
{

private:

	typedef shared_ptr< Module >(*Module_Factory) (Scene *);
	
	/// M�dulos existentes

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

	/// Almacena un nuevo m�dulo
	/// param name nombre del m�dulo
	/// param factory callback del m�dulo

	void reg(const string & name, Module_Factory factory)
	{
		modules[name] = factory;
	}

	/// Crea un nuevo m�dulo

	shared_ptr<Module> createModule(const string & name, Scene * scene);

};

#endif