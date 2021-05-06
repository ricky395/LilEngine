
/// Author: Ricardo Roldán Fernández
/// Date: 01/07/2018

#ifndef MODEL_COMPONENT_HEADER
#define MODEL_COMPONENT_HEADER

#include <string>
#include <memory>
#include <Model_Obj.hpp>

#include "Component.hpp"

/// Componente de objetos visuales

class Render_Component : public Component
{

private:

	/// Objeto representado

	std::shared_ptr< glt::Model > object;

public:

	/// Constructor
	/// param entity referencia a la entidad padre
	/// param path ruta del objeto

	Render_Component(Entity * entity, const std::string & path);

	/// Devuelve un puntero al objeto

	inline std::shared_ptr< glt::Model > get_model()
	{
		return object;
	}

	void initialize() override;

	void update(float delta_time) override;

	void stop() override;
};

#endif

