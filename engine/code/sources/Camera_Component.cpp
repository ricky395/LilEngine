
/// Author: Ricardo Roldán Fernández
/// Date: 02/07/2018

#include "Camera_Component.hpp"
#include "Transform_Component.hpp"
#include "Entity.hpp"

Camera_Component::Camera_Component(Entity * entity, float fov, float near,
								   float far, float aspect_ratio)
	: Component(entity),
	camera(new glt::Camera(fov, near, far, aspect_ratio))
{
}

void Camera_Component::initialize()
{
	// Obtengo el transform

	Transform_Component * transform = dynamic_cast<Transform_Component*>(parent->get_component("transform").get());

	// Se actualiza el nodo

	transform->reset_transform(camera);

	// Se aplica la transformación

	transform->init_values();
}

void Camera_Component::update(float delta_time)
{
}

void Camera_Component::stop()
{
}