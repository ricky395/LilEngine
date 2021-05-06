/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#ifndef TASK_HEADER
#define TASK_HEADER

#include <list>
#include <memory>
#include <Render_Node.hpp>

#include "Component.hpp"

class Scene;

using namespace std;

/// Tarea genérica de la escena

class Task
{

protected:

	/// Referencia a la escena

	Scene * scene;

	/// Prioridad de la tarea

	int  priority;
	
	/// Estado de la tarea

	bool finished;

	/// Lista de componentes

	std::list<shared_ptr< Component > > components;

public:

	/// Constructor
	/// param scene referencia a la escena
	/// param priority prioridad de la tarea
	/// param finished estado de la tarea

	Task(Scene * scene, int priority = 0, bool finished = false);

	/// Retorna el estado de la tarea

	bool is_finished() const;

	/// Inicia una tarea

	virtual void initialize() = 0;
	
	/// Termina una tarea

	virtual void finalize() = 0;
	
	/// Actualiza una tarea
	
	virtual void run(float delta_time) = 0;

	/// Añade un componente a una tarea

	inline void new_component(shared_ptr< Component > component)
	{
		components.push_back(component);
	}

	bool operator <  (const Task & other) const;

	bool operator >  (const Task & other) const;

	bool operator <= (const Task & other) const;

	bool operator >= (const Task & other) const;

	bool operator == (const Task & other) const;

	bool operator != (const Task & other) const;

};

/// Tarea de input

class Input_Task : public Task
{

public:

	/// Constructor
	/// param scene referencia a la escena
	/// param priority prioridad de la tarea
	/// param finished estado de la tarea

	Input_Task(Scene * scene, int priority = 3, bool finished = false);

	void initialize();
	void run(float delta_time);
	void finalize();
};

/// Tarea de actualización

class Update_Task : public Task
{

public:

	/// Constructor
	/// param scene referencia a la escena
	/// param priority prioridad de la tarea
	/// param finished estado de la tarea

	Update_Task(Scene * scene, int priority = 2, bool finished = false);
	
	void initialize();
	void run(float delta_time);
	void finalize();
};

/// Tarea de renderizado

class Render_Task : public Task
{

private:

	/// Referencia a la escena

	Scene * scene;

	/// Nodo de renderizado

	glt::Render_Node * render_node;

public:

	/// Constructor
	/// param scene referencia a la escena
	/// param render_node nodo de renderizado
	/// param priority prioridad de la tarea
	/// param finished estado de la tarea

	Render_Task(Scene * scene, glt::Render_Node * render_node,
		int priority = 1, bool finished = false);
	
	/// Devuelve el nodo de render

	inline glt::Render_Node * get_render_node()
	{
		return render_node;
	}

	/// Añade un nuevo nodo de render

	void add (const char * name, shared_ptr< glt::Node > node);

	void initialize();
	void run(float delta_time);
	void finalize();
};

#endif