
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#include "Scene.hpp"
#include "Task.hpp"

extern "C"
{
	#include <SDL.h>
}

Task::Task(Scene * scene, int priority, bool finished)
	:
	scene(scene),
	priority(priority),
	finished(finished)
{
}

bool Task::is_finished() const
{
	return finished;
}

bool Task::operator < (const Task & other) const
{
	return this->priority < other.priority;
}

bool Task::operator > (const Task & other) const
{
	return this->priority > other.priority;
}

bool Task::operator <= (const Task & other) const
{
	return this->priority <= other.priority;
}

bool Task::operator >= (const Task & other) const
{
	return this->priority >= other.priority;
}

bool Task::operator == (const Task & other) const
{
	return this->priority == other.priority;
}

bool Task::operator != (const Task & other) const
{
	return this->priority != other.priority;
}


//// Input_Task ////

Input_Task::Input_Task(Scene * scene, int priority, bool finished)
	:
	Task(scene, priority, finished)
{
}

void Input_Task::run(float delta_time)
{
	SDL_Event event;

	// Eventos de SDL

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		// Eventos de ventana

		case SDL_WINDOWEVENT:

			switch (event.window.event)
			{

			case SDL_WINDOWEVENT_RESIZED:
				scene->get_window()->set_size(event.window.data1, event.window.data2);
				break;

			case SDL_WINDOWEVENT_CLOSE:
				scene->get_kernel()->stop();
				break;
			}
			break;
		}
	}
}

void Input_Task::initialize()
{
	for (auto & component : components)
	{
		component->initialize();
	}
}

void Input_Task::finalize()
{
	for (auto & component : components)
	{
		component->stop();
	}
}


//// Update_Task ////

Update_Task::Update_Task(Scene * scene, int priority, bool finished)
	:
	Task(scene, priority, finished)
{
}

void Update_Task::run(float delta_time)
{
	for (auto & component : components)
	{
		component->update(delta_time);
	}
}

void Update_Task::initialize()
{
	for (auto & component : components)
	{
		component->initialize();
	}
}

void Update_Task::finalize()
{
	for (auto & component : components)
	{
		component->stop();
	}
}


//// Render_Task ////

Render_Task::Render_Task (Scene * scene, glt::Render_Node * render_node,
	int priority, bool finished)
	:
	Task(scene, priority, finished),
	render_node(render_node),
	scene(scene)
{
}

void Render_Task::add (const char * name, shared_ptr< glt::Node > node)
{
	render_node->add(name, node);
}

void Render_Task::run (float delta_time)
{
	// Se limpia la pantalla

	glClearColor(0.2f, 0.2f, 0.2f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Tarea de renderizado

	render_node->render();

	// Se intercambian los buffers de ventana

	scene->get_window()->swap_buffers();
}

void Render_Task::initialize ()
{
	for (auto & component : components)
	{
		component->initialize();
	}
}

void Render_Task::finalize ()
{
	for (auto & component : components)
	{
		component->stop();
	}
}