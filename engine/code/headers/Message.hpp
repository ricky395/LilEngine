//
///// Author: Ricardo Roldán Fernández
///// Date: 02/07/2018
//
//#include <unordered_map>
//
////#include "Variant.hpp"
//
///// Clase que define un mensaje
//
//class Message
//{
//
//	/// Id del mensaje
//
//	int action_id;
//	
//	//typedef std::unordered_map< int, Variant > Paramer_List;
//	
//	/// Lista de parámetros
//
//	//Paramer_List parameters;
//
//public:
//
//	/// Constructor de mensaje
//	/// param id id del mensaje
//
//	Message(int id) : action_id(id)
//	{
//	}
//	
//	/*Variant & operator [] (int key)
//	{
//		return parameters[key];
//	}*/
//	
//	bool operator == (const Message & other) const
//	{
//		return this->action_id == other.action_id;
//	}
//	
//	bool operator != (const Message & other) const
//	{
//		return this->action_id != other.action_id;
//	}
//	
//	/*operator int () const
//	{
//		return action_id;
//	}*/
//
//	int get_id()
//	{
//		return action_id;
//	}
//
//	const int get_id() const
//	{
//		return action_id;
//	}
//	
//};
//
////constexpr int hash(const char * s)
////{
////	int hash_value = 0;
////	
////	while (*s)
////	{
////		hash_value *= *(s++);
////	}
////	
////	return hash_value;
////}
