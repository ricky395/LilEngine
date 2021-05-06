
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#include "Kernel.hpp"
#include "Task.hpp"

void Kernel::execute()
{
	exit = false;

	// Se inicializan primero las tareas

	init();

	// Parámetros iniciales del timer

	auto previous_t = Time::now();
	auto  current_t = Time::now();

	// Delta time inicial

	delta_time = m_to_float(current_t - previous_t).count() * 0.001;

	while (!exit)
	{
		current_t = Time::now();
		
		// Se recorren todas las tareas

		std::list< Task * >::iterator it;

		for (it = task_list.begin(); it != task_list.end(); ++it)
		{
			Task * task = *it;

			task->run(delta_time);

			// Si alguna tarea finaliza...

			if (task->is_finished())
			{
				// Método finalize, que finaliza los componentes asociados

				task->finalize();

				// Se elimina

				task_list.remove(task);
			}
		}
		// Cálculo de delta time

		delta_time = m_to_float(current_t - previous_t).count() * 0.001;

		previous_t = current_t;
	}

}

void Kernel::init()
{
	for (auto & task : task_list)
	{
		task->initialize();
	}
}

void Kernel::stop()
{
	exit = true;
}

void Kernel::add(Task & task)
{
	// Se añade la tarea a la lista de tareas

	task_list.push_back(&task);

	// Se reordena la lista por prioridad de ejecución

	task_list.sort(compare);
}

bool Kernel::compare(const Task * a, const Task * b)
{
	return *a < *b;
}
