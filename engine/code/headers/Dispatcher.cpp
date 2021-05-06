//
///// Author: Ricardo Roldán Fernández
///// Date: 02/07/2018
//
//#include "Dispatcher.hpp"
//
//void Dispatcher::del_listener(Listener & listener)
//{
//	Listener_Map::iterator it;
//
//	for (it = listeners.begin(); it != listeners.end(); ++it)
//	{
//		if (it->second == &listener)
//		{
//			listeners.erase(it);
//			return;
//		}
//	}
//}
//
//void Dispatcher::send(Message & msg)
//{
//	for (auto & listener : listeners)
//	{
//		// Se controla el mensaje en los listeners
//
//		listener.second->handle(msg);
//	}
//}
