#pragma once
#include <memory>


template<typename t0 , typename t1>
class Node {

public:

	Node( t0 , t1 );

	std::shared_ptr<Node<t0 , t1>> getNext( );
	void setNext( std::shared_ptr<Node<t0 , t1>> );
	t0 getKey( );
	t1 getData( );

private:

	std::shared_ptr<Node<t0 , t1>> next;
	t0 key;
	t1 data;

	};

template<typename t0 , typename t1>
inline Node<t0 , t1>::Node( t0 key , t1 data ) : key( key ) , data( data ) , next( nullptr ) { }

template<typename t0 , typename t1>
inline std::shared_ptr<Node<t0 , t1>> Node<t0 , t1>::getNext( ) {
	return this->next;
	}

template<typename t0 , typename t1>
inline void Node<t0 , t1>::setNext( std::shared_ptr<Node<t0 , t1>>  next ) {
	this->next = next;
	}

template<typename t0 , typename t1>
inline t0 Node<t0 , t1>::getKey( ) {
	return this->key;
	}

template<typename t0 , typename t1>
inline t1 Node<t0 , t1>::getData( ) {
	return this->data;
	}
