//
///// Author: Ricardo Roldán Fernández
///// Date: 03/07/2018
//
//#include "Character_Control_Component.hpp"
//#include "Message_Types.hpp"
//
//Character_Control_Component::Character_Control_Component(Entity * entity)
//:
//	Component (entity),
//	parent	  (entity),
//	Up		  (Messages::MSG_UP),
//	Down	  (Messages::MSG_DOWN),
//	Left	  (Messages::MSG_LEFT),
//	Right	  (Messages::MSG_RIGHT)
//{
//
//	// Se añaden los listeners para cada mensaje
//
//	entity->get_scene()->get_dispatcher()->add_listener(Messages::MSG_UP   , *this);
//	entity->get_scene()->get_dispatcher()->add_listener(Messages::MSG_DOWN , *this);
//	entity->get_scene()->get_dispatcher()->add_listener(Messages::MSG_LEFT , *this);
//	entity->get_scene()->get_dispatcher()->add_listener(Messages::MSG_RIGHT, *this);
//}
//
//void Character_Control_Component::update(float delta_time)
//{
//	// Lee la entrada de teclado y manda un mensaje según la tecla pulsada
//
//	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP])
//	{
//		parent->get_scene()->get_dispatcher()->send(Up);
//	}
//
//	else if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN])
//	{
//		parent->get_scene()->get_dispatcher()->send(Down);
//	}
//
//	else if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])
//	{
//		parent->get_scene()->get_dispatcher()->send(Left);
//	}
//
//	else if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])
//	{
//		parent->get_scene()->get_dispatcher()->send(Right);
//	}
//}
//
//void Character_Control_Component::handle(const Message & message)
//{
//	// Controla los mensajes
//
//	switch (message.get_id()) //(int(message))
//	{
//
//	case MSG_UP:
//
//		cout << "UP pulsado" << endl;
//		break;
//
//	case MSG_DOWN:
//
//		cout << "DOWN pulsado" << endl;
//		break;
//
//	case MSG_RIGHT:
//
//		cout << "RIGHT pulsado" << endl;
//		break;
//
//	case MSG_LEFT:
//
//		cout << "LEFT pulsado" << endl;
//		break;
//	}
//}