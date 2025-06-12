#pragma once
#include "Node.h"
#include <iostream>


template<typename t>
class LinkNodes {

	int static count;
	int size;
	Node<t>* head;
	Node<t>* tail;

public:
	LinkNodes( );
	LinkNodes( const LinkNodes<t>& );
	LinkNodes( LinkNodes<t>&& ) noexcept;
	~LinkNodes( );

	LinkNodes<t>& Append( int data );
	LinkNodes<t>& Prepend( int data );
	LinkNodes<t>& InsertNode( int index , int data );
	LinkNodes<t>& DeleteFirst( );
	LinkNodes<t>& DeleteLast( );
	LinkNodes<t>& DeleteNode( int index );
	LinkNodes<t>& Reverse( );
	Node<t>& get( int index );
	void set( int index , int data );

	void display( );

	};



template<typename t>
int LinkNodes<t>::count = 0;

template<typename t>
LinkNodes<t>::LinkNodes( ) : head( nullptr ) , tail( nullptr ) {
	this->size = 0;
	count++;
	std::cout << "LinkNodes obj : " << count << std::endl;
	}

template<typename t>
LinkNodes<t>::LinkNodes( const LinkNodes<t>& source ) : size( source.size ) , head( nullptr ) , tail( nullptr ) {
	std::cout << "LinkNodes copy constractor called " << std::endl;
	this->head = new Node<t>( *source.head );
	this->tail = this->head;
	for( int i = 0; i < source.size - 1; i++ ) {
		this->Append( ( *source.head ).getNext( )->getData( ) );
		--this->size;
		}
	}

template<typename t>
LinkNodes<t>::LinkNodes( LinkNodes<t>&& source ) noexcept : size( source.size ) , head( source.head ) , tail( source.tail ) {
	std::cout << "LinkNodes move constractor called " << std::endl;
	source.head = nullptr;
	source.tail = nullptr;
	}

template<typename t>
LinkNodes<t>::~LinkNodes( ) {
	count--;
	std::cout << "Deleted LinkNodes total now : " << count << std::endl;
	auto temp = this->head;
	this->tail = nullptr;
	while( temp != nullptr ) {
		this->head = this->head->getNext( );
		delete temp;
		temp = this->head;
		}
	delete this->head;
	delete this->tail;
	}

template<typename t>
LinkNodes<t>& LinkNodes<t>::Append( int data ) {
	if( this->size == 0 ) {
		this->head = this->tail = new Node<t>( data );
		this - size++;
		return *this;
		}
	else if( this->size == 1 ) {
		this->tail = new Node<t>( data );
		this->head->setNext( this->tail );
		this - size++;
		return *this;
		}
	auto temp = this->tail;
	this->tail = new Node<t>( data );
	temp->setNext( this->tail );
	this - size++;
	return *this;
	}


template<typename t>
LinkNodes<t>& LinkNodes<t>::Prepend( int data ) {
	if( this->size == 0 ) {
		this->head = this->tail = new Node<t>( data );
		this - size++;
		return *this;
		}
	else if( this->size == 1 ) {
		this->head = new Node<t>( data );
		this->head->setNext( this->tail );
		this - size++;
		return *this;
		}
	auto temp = this->head;
	this->head = new Node<t>( data );
	this->head->setNext( temp );
	this - size++;
	return *this;
	}

template<typename t>
LinkNodes<t>& LinkNodes<t>::InsertNode( int index , int data ) {
	Node<t>* n = new Node<t>( data );
	n->setNext( this->get( index - 1 ).getNext( ) );
	this->get( index - 1 ).setNext( n );
	n = nullptr;
	delete n;
	++this->size;
	return *this;
	}


template<typename t>
LinkNodes<t>& LinkNodes<t>::DeleteFirst( ) {
	if( this->size != 0 ) {
		auto temp = this->head;
		this->head = this->head->getNext( );
		temp->setNext( nullptr );
		delete temp;
		--this->size;
		return *this;
		}
	}


template<typename t>
LinkNodes<t>& LinkNodes<t>::DeleteLast( ) {
	auto temp = this->tail;
	this->tail = this->get( this->size - 3 ).getNext( );
	this->tail->setNext( nullptr );
	delete temp;
	--this->size;
	return *this;
	}


template<typename t>
LinkNodes<t>& LinkNodes<t>::DeleteNode( int index ) {
	auto ptr = this->get( index - 1 ).getNext( );
	auto temp = this->get( index - 1 ).getData( );
	this->get( index - 1 ) = std::move( *ptr );
	this->get( index - 1 ).setData( temp );
	delete ptr;
	--this->size;
	return *this;
	}


template<typename t>
LinkNodes<t>& LinkNodes<t>::Reverse( ) {
	this->tail = this->head;
	auto temp = this->head->getNext( );
	auto tptr = this->tail;
	for( int i = 0; i < size; i++ ) {
		if( temp != nullptr ) {
			this->head = temp;
			temp = temp->getNext( );
			this->head->setNext( tptr );
			tptr = this->head;
			}
		}
	this->tail->setNext( nullptr );
	return *this;
	}


template<typename t>
Node<t>& LinkNodes<t>::get( int index ) {
	if( index < this->size && index >= 0 ) {
		auto ptr = this->head;
		for( int i = 0; i < index; i++ ) {
			ptr = ( *ptr ).getNext( );
			}
		return *ptr;
		}
	}


template<typename t>
void LinkNodes<t>::set( int index , int data ) {
	if( index < this->size && index >= 0 ) {
		auto ptr = this->head;
		for( int i = 0; i < index; i++ ) {
			ptr = ( *ptr ).getNext( );
			}
		ptr->setData( data );
		}
	}


template<typename t>
void LinkNodes<t>::display( ) {
	auto ptr = this->head;
	for( int i = 0; i < this->size; i++ ) {
		std::cout << i << " : ";
		ptr->displyMe( );
		ptr = ( *ptr ).getNext( );
		}
	}






