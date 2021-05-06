//
///// Author: Ricardo Roldán Fernández
///// Date: 02/07/2018
//
//#include "Message.hpp"
//
///// Maneja los listeners y el envío de mensajes
//
//class Dispatcher
//{
//
//public:
//
//	/// Estructura genérica para un listener
//
//	struct Listener
//	{
//		virtual     ~Listener() {}		
//		virtual void handle  (const Message & ) = 0;
//	};
//
//private:
//
//	typedef std::unordered_map< int, Listener * > Listener_Map;
//
//	/// Lista de listeners
//
//	Listener_Map listeners;
//
//public:
//
//	/// Se añade un nuevo listener
//
//	void add_listener(int id, Listener & listener)
//	{
//		listeners[id] = &listener;
//	}
//
//	/// Se elimina un listener
//	/// param listener listener a eliminar
//	void del_listener(Listener & listener);
//
//	/// Envía un mensaje a los listeners
//	/// param msg mensaje a enviar
//
//	void send(Message & msg);
//
//};