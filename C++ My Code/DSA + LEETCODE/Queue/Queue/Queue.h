#pragma once
#include "Node.h"
#include <iostream>
#include <memory>

template <typename t>
class Queue {

public:

	Queue( );
	~Queue( );

	void enqueue( int data );
	Node<t> dequeue( );
	void display( ) const;

private:

	static int count;
	std::shared_ptr<Node<t>> front;
	std::shared_ptr<Node<t>> back;

	};

template<typename t>
int Queue<t>::count = 0;

template<typename t>
inline Queue<t>::Queue( ) : front( nullptr ) , back( nullptr ) {
	std::cout << "Queue created count is : " << ++count << std::endl;
	}

template<typename t>
inline Queue<t>::~Queue( ) {
	std::cout << "Queue destroyed count is : " << --count << std::endl;
	std::cout << "number of pointer in the front is  : " << this->front.use_count( ) << std::endl;
	std::cout << "number of pointer in the back is  : " << this->back.use_count( ) << std::endl;
	}

template<typename t>
inline void Queue<t>::enqueue( int data ) {
	std::shared_ptr<Node<t>> newNode = std::make_shared<Node<t>>( data );
	if( !this->front ) {
		this->front = newNode;
		this->back = newNode;
		}
	else {
		this->back->setNext( newNode );
		this->back = newNode;
		}
	}

template<typename t>
inline Node<t> Queue<t>::dequeue( ) {
	if( this->front ) {
		auto temp = this->front->getData( );
		auto ptr = this->front;
		this->front = this->front->getNext( );
		if( !this->front ) {
			this->back = nullptr;
			}
		ptr->setNext( nullptr );
		return temp;
		}
	}

template<typename t>
inline void Queue<t>::display( ) const {
	if( this->front != nullptr ) {
		this->front->displayMe( );
		}
	}



