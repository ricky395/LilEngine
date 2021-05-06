
/// Author: Ricardo Roldán Fernández
/// Date: 29/06/2018

#include "Entity.hpp"


Entity::Entity(Scene * scene) : parent(scene)
{
}

void Entity::initialize()
{
	for (auto & component : components)
	{
		component.second->initialize();
	}
}

void Entity::update(float deltaTime)
{
	for (auto & component : components)
	{
		component.second->update(deltaTime);
	}
}

void Entity::add_component(const string & name, shared_ptr< Component > & component)
{
	components[name] = component;
}
