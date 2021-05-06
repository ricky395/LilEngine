//
///// Author: Ricardo Roldán Fernández
///// Date: 03/07/2018
//
//#ifndef CHARACTER_CONTROL_HEADER
//#define CHARACTER_CONTROL_HEADER
//
//#include <iostream>
//
////extern "C"
////{
////	#include <SDL_keyboard.h>
////}
//
//#include "Dispatcher.hpp"
//#include "Component.hpp"
//#include "Entity.hpp"
//#include "Message.hpp"
//
///// Componente de manejo del personaje
//
//class Character_Control_Component : public Component, public Dispatcher::Listener
//{
//
//private:
//
//	/// Entidad padre
//
//	Entity * parent;
//
//	/// Estado del teclado en SDL
//
//	const uint8_t * state;
//
//	/// Mensaje de movimiento hacia arriba
//
//	Message Up;
//
//	/// Mensaje de movimiento hacia abajo
//
//	Message Down;
//
//	/// Mensaje de movimiento hacia la izquierda
//
//	Message Left;
//
//	/// Mensaje de movimiento hacia la derecha
//
//	Message Right;
//
//public:
//
//	/// Constructor del componente del personaje
//	/// param entity Entidad padre
//
//	Character_Control_Component(Entity * entity);
//
//	/// Inicializa los elementos necesarios del componente
//
//	void initialize() override
//	{
//		// Inicializa el estado del teclado
//
//		state = SDL_GetKeyboardState(nullptr);
//	}
//
//	void update(float delta_time) override;
//
//	void stop() override
//	{
//	}
//
//	/// Maneja el mensaje recibido
//
//	void handle(const Message & message);
//
//};
//
//#endif