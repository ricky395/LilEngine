
/// Author: Ricardo Rold�n Fern�ndez
/// Date: 26/06/2018

#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <string>
#include <memory>
#include <map>

#include "Component.hpp"
#include "Scene.hpp"

using namespace std;

/// Definici�n de entidad en la escena

class Entity
{

private:
	
	/// Mapa de componentes

	map< string, shared_ptr< Component > > components;

	/// Referencia a la escena

	Scene * parent;

public:

	/// Constructor de entidad
	/// param scene referencia a la escena

	Entity(Scene * scene);

	void initialize();

	void update(float deltaTime);

	/// Se a�ade un nuevo componente a la escena
	/// param name nombre del componente
	/// param component componente a a�adir

	void add_component(const string & name, shared_ptr< Component > & component);

	/// Devuelve la referencia a la escena

	inline Scene * get_scene()
	{
		return parent;
	}

	/// Devuelve un componente seg�n un nombre
	/// param name nombre del componente

	inline std::shared_ptr<Component> get_component(const string & name)
	{
		return components[name];
	}

};

#endif
