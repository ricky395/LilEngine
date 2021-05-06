
/// Author: Ricardo Roldán Fernández
/// Date: 02/07/2018

#ifndef LIGHT_COMPONENT_HEADER
#define LIGHT_COMPONENT_HEADER

#include <memory>
#include <Light.hpp>

#include "Component.hpp"

using namespace std;

/// Componente de luz

class Light_Component : public Component
{

	private:

		/// Objeto luz

		shared_ptr< glt::Light > light;

	public:

		/// Constructor
		/// param entity referencia a la entidad padre

		Light_Component(Entity * entity);
		
		/// Devuelve un puntero al objeto luz

		shared_ptr< glt::Light > get_light() const
		{
			return light;
		}

	public:

		void initialize() override;
		void update(float deltaTime) override;
		void stop() override;

};

#endif;