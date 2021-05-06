
/// Author: Ricardo Roldán Fernández
/// Date: 02/07/2018

#ifndef CAMERA_COMPONENT_HEADER
#define CAMERA_COMPONENT_HEADER

#include <memory>
#include <Camera.hpp>

#include "Component.hpp"

using namespace std;

/// Componente que maneja la cámara de la escena

class Camera_Component : public Component
{

private:

	/// Objeto cámara

	shared_ptr< glt::Camera > camera;

public:

	/// Constructor del componente
	/// param entity entidad padre
	/// param fov campo de visión de la cámara
	/// param near plano de recorte cercano
	/// param far plano de recorte lejano
	/// param aspect_ratio relación de aspecto de la cámara
	Camera_Component(Entity * entity, float fov = 60.f, float near = 0.1f,
					 float far = 10000.f, float aspect_ratio = 1.f);


	/// Devuelve el objeto cámara
	shared_ptr< glt::Camera > get_camera() const
	{
		return camera;
	}

	void initialize() override;
	void update(float delta_time) override;
	void stop() override;
};

#endif