
/// Author: Ricardo Rold�n Fern�ndez
/// Date: 01/07/2018

#include <iostream>

#include "ModuleCreation.hpp"
#include "Module.hpp"


ModuleCreation * ModuleCreation::instance = nullptr;

ModuleCreation::ModuleCreation()
{
	// Se crean los m�dulos base

	reg("render", Render_Module::create);
	reg("update", Update_Module::create);
	reg("input" ,  Input_Module::create);
}

shared_ptr<Module> ModuleCreation::createModule(const string & name, Scene * scene)
{
	// En caso de que no exista tal m�dulo

	if (modules.count(name))
	{
		std::cout << "Module " << name << " created" << std::endl;

		// Se crea uno nuevo

		return modules[name](scene);
	}

	return shared_ptr<Module>();
}