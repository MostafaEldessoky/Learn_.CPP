#pragma once
#include <iostream>
#include <iostream>
#include <ostream>

template<typename t>
class Node {

	int static count;
	t data;
	Node<t>* next;

public:
	Node( t data = 0 );
	Node( const Node<t>& source );
	Node<t>& operator=( const Node<t>& source );
	Node( Node<t>&& source ) noexcept;
	Node<t>& operator=( Node<t>&& source ) noexcept;
	~Node( );

	t getData( ) const;
	void setData( t data );
	Node<t>* getNext( ) const;
	void setNext( Node<t>* next );
	void displyMe( );
	};


template<typename t>
int Node<t>::count = 0;

template<typename t>
Node<t>::Node( t data ) : data( data ) , next( nullptr ) {
	count++;
	std::cout << "Node obj : " << count << std::endl;
	}

template<typename t>
Node<t>::Node( const Node<t>& source ) : data( source.data ) , next( source.next ) {
	std::cout << "Node copy constractor called " << std::endl;
	}

template<typename t>
Node<t>& Node<t>::operator=( const Node<t>& source ) {
	std::cout << "Node copy assinment called " << std::endl;
	if( this != &source ) {
		this->data = source.data;
		this->next = source.next;
		}
	return *this;
	}

template<typename t>
Node<t>& Node<t>::operator=( Node<t>&& source ) noexcept {
	count++;
	std::cout << "Node move assinment called " << count << std::endl;
	this->next = source.next;
	this->data = source.data;
	source.next = nullptr;
	return *this;
	}

template<typename t>
Node<t>::Node( Node<t>&& source ) noexcept : data( source.data ) , next( source.next ) {
	count++;
	std::cout << "Node move constractor called " << count << std::endl;
	source.next = nullptr;
	}

template<typename t>
Node<t>::~Node( ) {
	count--;
	std::cout << "Node deleted total now : " << count << std::endl;
	next = nullptr;
	delete next;
	}


template<typename t>
void Node<t>::displyMe( ) {
	std::cout << "My data : " << this->data << " My next : " << this->next << std::endl;
	}

template<typename t>
t Node<t>::getData( ) const {
	return this->data;
	}

template<typename t>
Node<t>* Node<t>::getNext( ) const {
	return this->next;
	}

template<typename t>
void Node<t>::setData( t data ) {
	this->data = data;
	}

template<typename t>
void Node<t>::setNext( Node<t>* next ) {
	this->next = next;
	}




