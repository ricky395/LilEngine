
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#include "Scene.hpp"
#include "ModuleCreation.hpp"
#include "Entity.hpp"

Scene::Scene(Window * window)
:
	window	   (window),
	kernel	   (new Kernel())
	//dispatcher (new Dispatcher())
{
	loaded = load_scene();
}

bool Scene::load_scene()
{	
	// Módulos base

	modules["render"] = ModuleCreation::Instance()->createModule("render", this);
	modules["update"] = ModuleCreation::Instance()->createModule("update", this);
	modules["input" ] = ModuleCreation::Instance()->createModule("input" , this);

	// Se crean las entidades

	entities["object"] = make_shared< Entity >(this);
	entities["camera"] = make_shared< Entity >(this);
	entities["player"] = make_shared< Entity >(this);

	// Se crean los componentes de cada entidad

	modules["render"]->create_component("cam", "camera",  &*entities["camera"]);
	modules["update"]->create_component("tr1",  "transf", &*entities["camera"]);

	modules["render"]->create_component("obj", "model",   &*entities["object"], "../../assets/cat.obj");
	modules["update"]->create_component("tr2", "transf2", &*entities["object"]);

	modules["input"]->create_component("player", "controller", &*entities["player"]);
	
	// Se inicia la escena

	init();

	// Se ejecuta la escena (hpp)

	run();

	return true;
}

void Scene::init()
{
	for (auto & module : modules)
	{
		Task * task = module.second->get_task();

		if (task)
		{
			kernel->add(*task);
		}
	}
}