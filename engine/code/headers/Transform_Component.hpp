
/// Author: Ricardo Rold�n Fern�ndez
/// Date: 26/06/2018

#ifndef TRANSFORM_COMPONENT_HEADER
#define TRANSFORM_COMPONENT_HEADER

#include <Node.hpp>
#include "Component.hpp"

using namespace glm;
using namespace std;

/// Componente transform de un objeto

class Transform_Component : public Component
{

private:

	/// Nodo de transform

	shared_ptr< glt::Node > transformation;

	/// Posici�n del objeto

	vec3 position;
	
	/// Rotaci�n del objeto

	vec3 rotation;
	
	/// Escala del objeto
	
	vec3 scale;

public:

	/// Constructor
	/// param entity referencia a la entidad padre
	/// param position posici�n del objeto
	/// param rotation rotaci�n del objeto
	/// param scale escala del objeto

	Transform_Component(Entity * entity, vec3 position = vec3(0, 0, 0), vec3 rotation = vec3(0, 0, 0), glm::vec3 scale = vec3(1, 1, 1));

	/// Se actualiza el nodo

	void reset_transform(shared_ptr< glt::Node > transform);

	/// Se dan los valores iniciales del objeto

	void init_values();

	/// Resetea el nodo de transformaci�n

	void reset_position();

	/// A�ade al objeto una posici�n

	void translate(glm::vec3 position);

	/// Establece la rotaci�n del objeto

	void set_rotation(glm::vec3 rotation);

	/// Establece la escala del objeto

	void set_scale(glm::vec3 scale);

	void initialize() override;
	
	void update(float deltaTime) override;

	void stop() override;
	
};

#endif