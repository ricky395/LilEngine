
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#include <iostream>

#include "Module.hpp"
#include "Entity.hpp"
#include "Scene.hpp"
#include "Render_Component.hpp"
#include "Camera_Component.hpp"
#include "Light_Component.hpp"
#include "Transform_Component.hpp"
//#include "Character_Control_Component.hpp"

Module::Module(Scene * scene) : scene(scene) 
{
}

Module::~Module() 
{ 
	delete scene; 
}

//// Render_Module ////

Render_Module::Render_Module(Scene * parent_scene)
	:
	Module		(parent_scene),
	render_task	(parent_scene, new glt::Render_Node)
{
}

void Render_Module::create_component(const char * name, const char * type, Entity * entity, const char * path)
{
	const std::string t = type;

	if (t == "model")
	{
		// Se crea el objeto

		shared_ptr< Render_Component > obj(new Render_Component(entity, path));
		
		// Se añade el componente a la tarea

		render_task.new_component(obj);

		// Se añade el objeto de render a la tarea

		render_task.add(name, obj->get_model());

		// Se añade el objeto a la entidad

		entity->add_component(name, (shared_ptr< Component >) obj);
	}

	else if (t == "camera")
	{
		// Se crea el objeto

		shared_ptr< Camera_Component > camera(new Camera_Component(entity));

		// Se añade el componente a la tarea

		render_task.new_component(camera);

		// Se añade el objeto de render a la tarea

		render_task.add(name, camera->get_camera());

		// Se añade el objeto a la entidad

		entity->add_component(name, (shared_ptr< Component >) camera);
	}

	else if (t == "light")
	{
		// Se crea el objeto

		shared_ptr< Light_Component > light(new Light_Component(entity));

		// Se añade el componente a la tarea

		render_task.new_component(light);

		// Se añade el objeto de render a la tarea

		render_task.add(name, light->get_light());

		// Se añade el objeto a la entidad

		entity->add_component(name, (shared_ptr< Component >) light);
	}

	std::cout << "Component " << name << " of type " << type << " created on Render_Module" << std::endl;
}


//// Update Module ////

Update_Module::Update_Module(Scene * parent_scene)
	:
	Module		(parent_scene),
	update_task	(parent_scene)
{
}

void Update_Module::create_component(const char * name, const char * type, Entity * entity, const char * path)
{

	if (type == "controller")
	{
		//// Se crea el objeto

		//shared_ptr< Character_Control_Component > controller
		//(
		//	new Character_Control_Component(entity)
		//);

		//// Se añade la tarea

		//update_task.new_component(shared_ptr< Component >(controller));

		//// Se añade el objeto a la entidad

		//entity->add_component(name, shared_ptr< Component >(controller));
	}

	// Se crea el objeto

	shared_ptr< Transform_Component > transform(new Transform_Component(entity));

	// Se añade el objeto a la tarea update

	update_task.new_component(transform);

	// Se añade el objeto a la entidad

	entity->add_component("transform", shared_ptr< Component >(transform));

	std::cout << "Component " << name << " created on Update_Module" << std::endl;
}


//// Input_Module ////

Input_Module::Input_Module(Scene * parent_scene)
	:
	Module	   (parent_scene),
	input_task (parent_scene)
{
}

void Input_Module::create_component(const char * name, const char * type, Entity * entity, const char * path)
{

	if (type == "controller")
	{
		//// Se crea el objeto

		//shared_ptr< Character_Control_Component > controller
		//(
		//	new Character_Control_Component(entity)
		//);

		//// Se añade la tarea

		//update_task.new_component(shared_ptr< Component >(controller));

		//// Se añade el objeto a la entidad

		//entity->add_component(name, shared_ptr< Component >(controller));
	}

	// Se crea el objeto

	shared_ptr< Transform_Component > transform(new Transform_Component(entity));

	// Se añade el objeto a la tarea input

	input_task.new_component(transform);

	// Se añade el objeto a la entidad

	entity->add_component("transform", shared_ptr< Component >(transform));

	std::cout << "Component " << name << " created on Input_Module" << std::endl;
}