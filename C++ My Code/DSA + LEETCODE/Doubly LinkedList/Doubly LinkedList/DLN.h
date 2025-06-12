#pragma once
#include "Node.h"
#include <iostream>

template<typename t>
class DLN {
	static int count;
	int size;
	Node<t>* head;
	Node<t>* tail;

public:
	DLN( );
	DLN( const DLN<t>& ) = delete;
	DLN( DLN<t>&& );
	~DLN( );

	void display( );
	DLN<t>& append( t );
	DLN<t>& prepend( t );
	DLN<t>& insert( int , t );
	DLN<t>& deleteFirst( );
	DLN<t>& deleteLast( );
	DLN<t>& deleteNode( int );
	Node<t>& get( int );
	DLN<t>& set( int , t );


	};


template<typename t>
int DLN<t>::count = 0;

template<typename t>
DLN<t>::DLN( ) : size( 0 ) , head( nullptr ) , tail( nullptr ) {
	count++;
	std::cout << "DLN Constractor : " << count << std::endl;
	}

template<typename t>
DLN<t>::DLN( DLN<t>&& source ) : size( source.size ) , head( source.head ) , tail( source.tail ) {
	source.head = nullptr;
	source.tail = nullptr;
	std::cout << "DLN Move Constractor" << std::endl;
	}

template<typename t>
DLN<t>::~DLN( ) {
	count--;
	std::cout << "DLN Destructor : " << count << std::endl;
	auto temp = this->head;
	for( int i = 0; i < this->size; i++ ) {
		this->head = this->head->getMyNext( );
		temp->setMyNext( nullptr );
		temp->setMyPrev( nullptr );
		delete temp;
		temp = this->head;
		}
	delete this->head;
	this->tail = nullptr;
	delete this->tail;
	}

template<typename t>
void DLN<t>::display( ) {
	auto temp = this->head;
	for( int i = 0; i < this->size; i++ ) {
		std::cout << i << " : ";
		temp->displayMe( );
		std::cout << std::endl;
		temp = temp->getMyNext( );
		}
	}

template<typename t>
DLN<t>& DLN<t>::append( t data ) {
	if( this->size != 0 ) {
		auto temp = this->tail;
		this->tail = new Node<t>( data );
		this->tail->setMyPrev( temp );
		temp->setMyNext( this->tail );
		++this->size;
		return *this;
		}
	this->tail = this->head = new Node<t>( data );
	++this->size;
	return *this;
	}

template<typename t>
DLN<t>& DLN<t>::prepend( t data ) {
	if( this->size != 0 ) {
		auto temp = this->head;
		this->head = new Node<t>( data );
		this->head->setMyNext( temp );
		temp->setMyPrev( this->head );
		++this->size;
		return *this;
		}
	this->tail = this->head = new Node<t>( data );
	++this->size;
	return *this;
	}

template<typename t>
DLN<t>& DLN<t>::insert( int index , t data ) {
	if( index >= 0 && index < this->size ) {
		if( index == 0 ) {
			return this->prepend( data );
			}
		auto temp1 = this->head;
		auto temp2 = this->head->getMyNext( );
		auto temp3 = new Node<t>( data );
		for( int i = 1; i < index; i++ ) {
			temp1 = temp1->getMyNext( );
			temp2 = temp2->getMyNext( );
			}
		temp3->setMyNext( temp2 );
		temp3->setMyPrev( temp1 );
		temp1->setMyNext( temp3 );
		temp2->setMyPrev( temp3 );
		++this->size;
		return *this;
		}

	}

template<typename t>
DLN<t>& DLN<t>::deleteFirst( ) {
	auto temp = this->head;
	this->head = this->head->getMyNext( );
	temp->setMyNext( nullptr );
	this->head->setMyPrev( nullptr );
	delete temp;
	--this->size;
	return *this;
	}

template<typename t>
DLN<t>& DLN<t>::deleteLast( ) {
	auto temp = this->tail;
	this->tail = this->tail->getMyPrev( );
	temp->setMyPrev( nullptr );
	this->tail->setMyNext( nullptr );
	delete temp;
	--this->size;
	return *this;
	}

template<typename t>
DLN<t>& DLN<t>::deleteNode( int index ) {
	if( index >= 0 && index < this->size ) {
		if( index == 0 ) {
			return this->deleteFirst( );
			}
		if( index == this->size - 1 ) {
			return this->deleteLast( );
			}
		auto temp1 = this->head;
		auto temp2 = this->head->getMyNext( );
		auto temp3 = this->head->getMyNext( )->getMyNext( );
		for( int i = 1; i < index; i++ ) {
			temp1 = temp1->getMyNext( );
			temp2 = temp2->getMyNext( );
			temp3 = temp3->getMyNext( );
			}
		temp1->setMyNext( temp3 );
		temp3->setMyPrev( temp1 );
		temp2->setMyNext( nullptr );
		temp2->setMyPrev( nullptr );
		delete temp2;
		--this->size;
		return *this;
		}
	}

template<typename t>
Node<t>& DLN<t>::get( int index ) {
	if( index >= 0 && index < this->size ) {
		auto temp = this->head;
		for( int i = 0; i < index; i++ ) {
			temp = temp->getMyNext( );
			}
		return *temp;
		}
	}

template<typename t>
DLN<t>& DLN<t>::set( int index , t data ) {
	this->get( index ).setData( data );
	return *this;
	}


