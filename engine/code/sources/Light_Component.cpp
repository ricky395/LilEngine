
/// Author: Ricardo Roldán Fernández
/// Date: 02/07/2018

#include "Light_Component.hpp"
#include "Transform_Component.hpp"
#include "Entity.hpp"

Light_Component::Light_Component(Entity * entity)
	: 
	Component (entity), 
	light	  (new glt::Light())
{
}

void Light_Component::initialize()
{
	// Obtengo el transform

	Transform_Component * transform = dynamic_cast< Transform_Component * >(parent->get_component("transform").get());

	// Se actualiza el nodo

	transform->reset_transform(light);

	// Se aplica la transformación

	transform->init_values();
}

void Light_Component::update(float deltaTime)
{
}

void Light_Component::stop()
{
}