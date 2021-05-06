
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#include "Transform_Component.hpp"

Transform_Component::Transform_Component(Entity * entity, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: Component(entity),
	position(position),
	rotation(rotation),
	scale(scale)
{
}

void Transform_Component::reset_transform(shared_ptr< glt::Node > transform)
{
	transformation = transform;
}

void Transform_Component::init_values()
{
	// Se resetea la transformación

	reset_position();

	// Se aplican las nuevas transformaciones

	translate(position);
	set_rotation(rotation);
	set_scale(scale);
}

void Transform_Component::reset_position()
{
	transformation->reset_transformation();
}

void Transform_Component::translate(glm::vec3 position)
{
	transformation->translate(position);
}

void Transform_Component::set_rotation(glm::vec3 rotation)
{
	transformation->rotate_around_x(rotation[0]);
	transformation->rotate_around_y(rotation[1]);
	transformation->rotate_around_z(rotation[2]);
}

void Transform_Component::set_scale(glm::vec3 scale)
{
	transformation->scale(scale[0], scale[1], scale[2]);
}

void Transform_Component::initialize()
{
}

void Transform_Component::update(float deltaTime)
{
}

void Transform_Component::stop()
{
}