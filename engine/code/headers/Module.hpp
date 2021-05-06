
/// Author: Ricardo Roldán Fernández
/// Date: 01/07/2018

#ifndef MODULE_HEADER
#define MODULE_HEADER

#include <string>

#include "Task.hpp"

/// Módulo genérico que maneja los componentes de las tareas

class Module
{

private:

	/// Referencia a la escena

	const Scene * scene;

public:

	/// Constructor
	/// param scene referencia a la escena

	Module(Scene * scene);

	virtual ~Module();

public:

	virtual Task * get_task() = 0;

	virtual const Task * get_task() const = 0;

	/// Crea un nuevo componente
	/// param name nombre del componente
	/// param type tipo de componente
	/// param entity referencia a la entidad padre
	/// param path ruta del objeto a cargar (en caso de necesitarla)

	virtual void create_component(const char * name, const char * type, Entity * entity, const char * path = "") = 0;
};



class Entity;

/// Módulo de renderizado

class Render_Module : public Module
{
	/// Tarea de renderizado

	Render_Task render_task;

public:

	/// Constructor
	/// param parent_scene referencia a la escena

	Render_Module(Scene * parent_scene);

	~Render_Module()
	{
	}

	/// Devuelve la tarea

	inline Task * get_task() override
	{
		return &render_task;
	}

	/// Devuelve la tarea (versión constante)

	const inline Task * get_task() const override
	{
		return &render_task;
	}
	
	/// Crea un nuevo módulo de render
	/// param scene referencia a la escena

	static shared_ptr< Module > create(Scene * scene)
	{
		return shared_ptr< Module >(new Render_Module(scene));
	}
	
	/// Crea un nuevo componente
	/// param name nombre del componente
	/// param type tipo de componente
	/// param entity referencia a la entidad padre
	/// param path ruta del objeto a cargar (en caso de necesitarla)

	void create_component(const char * name, const char * type, Entity * entity, const char * path = "") override;

};

/// 
class Update_Module : public Module
{

private:

	/// Tarea de update

	Update_Task update_task;

public:

	/// Constructor
	/// param parent_scene referencia a la escena

	Update_Module(Scene * parent_scene);

	~Update_Module()
	{
	}

	/// Devuelve la tarea

	inline Task * get_task() override
	{
		return &update_task;
	}

	/// Devuelve la tarea (versión constante)

	const inline Task * get_task() const override
	{
		return &update_task;
	}
	
	/// Crea un nuevo módulo de update
	/// param scene referencia a la escena

	static shared_ptr< Module > create(Scene * scene)
	{
		return shared_ptr< Module >(new Update_Module(scene));
	}

	/// Crea un nuevo componente
	/// param name nombre del componente
	/// param type tipo de componente
	/// param entity referencia a la entidad padre
	/// param path ruta del objeto a cargar (en caso de necesitarla)
	void create_component(const char * name, const char * type, Entity * entity, const char * path = "") override;

};


class Input_Module : public Module
{

private:

	/// Tarea de input

	Input_Task input_task;

public:

	/// Constructor
	/// param parent_scene referencia a la escena

	Input_Module(Scene * parent_scene);

	~Input_Module()
	{
	}

	/// Devuelve la tarea

	inline Task * get_task() override
	{
		return &input_task;
	}

	/// Devuelve la tarea (versión constante)

	const inline Task * get_task() const override
	{
		return &input_task;
	}

	/// Crea un nuevo módulo de update
	/// param scene referencia a la escena

	static shared_ptr< Module > create(Scene * scene)
	{
		return shared_ptr< Module >(new Input_Module(scene));
	}

	/// Crea un nuevo componente
	/// param name nombre del componente
	/// param type tipo de componente
	/// param entity referencia a la entidad padre
	/// param path ruta del objeto a cargar (en caso de necesitarla)
	void create_component(const char * name, const char * type, Entity * entity, const char * path = "") override;
};

#endif