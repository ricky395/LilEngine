
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#ifndef COMPONENT_HEADER
#define COMPONENT_HEADER

class Entity;

/// Clase componente genérica

class Component
{

protected:

	/// Referencia a la entidad padre

	Entity * parent;

public:

	/// Constructor de componente genérico
	/// param entity Entidad padre

	Component(Entity * entity) : parent(entity)
	{
	}

	/// Inicializa el componente

	virtual void initialize() = 0;

	/// Actualiza el componente en cada vuelta de bucle
	/// param delta_time tiempo transcurrido entre el anterior frame y el actual

	virtual void update(float delta_time) = 0;

	/// Termina la ejecución del componente

	virtual void stop() = 0;

};

#endif
