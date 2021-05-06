
/// Author: Ricardo Roldán Fernández
/// Date: 26/06/2018

#ifndef KERNEL_HEADER
#define KERNEL_HEADER

#include <list>
#include <chrono>

class Task;

/// Maneja las tareas de una escena

class Kernel
{
	typedef std::list< Task * > Task_List;
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::duration<float, std::milli> m_to_float;
	
	/// Lista de tareas

	Task_List task_list;

	/// Flag que indica la ejecución del kernel

	bool exit;

	/// Tiempo transcurrido entre el frame actual y el anterior

	float delta_time;
	
public:

	/// Ejecuta las tareas de la lista

	void execute();
	
	/// Inicializa las tareas de la lista

	void init();

	/// Para las tareas de la lista

	void stop();
	
	/// Añade una nueva tarea al kérnel
	/// task tarea a añadir

	void add(Task & task);
	
	/// Comparador de tareas según prioridad
	/// param a primera tarea
	/// param b segunda tarea

	static bool compare(const Task * a, const Task * b);
	
};

#endif