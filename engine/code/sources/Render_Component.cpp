
/// Author: Ricardo Roldán Fernández
/// Date: 01/07/2018

#include "Entity.hpp"
#include "Render_Component.hpp"
#include "Transform_Component.hpp"

Render_Component::Render_Component(Entity * entity, const std::string & file_path)
	: 
	Component (entity), 
	object	  (new glt::Model_Obj(file_path))
{
}

void Render_Component::initialize()
{
	// Obtengo el transform

	Transform_Component * transform = dynamic_cast< Transform_Component * >(parent->get_component("transform").get());

	// Se actualiza el nodo

	transform->reset_transform(object);

	// Se aplica la transformación

	transform->init_values();
}

void Render_Component::update(float delta_time)
{
}

void Render_Component::stop()
{
}