#pragma once
#include "Node.h"
#include <iostream>
#include <memory>
#include <ostream>

template <typename t>
class Stack {

public:

	Stack( );
	Stack( const Stack<t>& );
	Stack( Stack<t>&& );
	~Stack( );

	void display( ) const;
	void push( t value );
	Node<t> pop( );

private:

	static int count;
	std::unique_ptr<Node<t>> top;

	};


template <typename t>
int Stack<t>::count = 0;

template<typename t>
Stack<t>::Stack( ) : top( nullptr ) {
	std::cout << "Stack created : " << ++count << std::endl;
	}

template<typename t>
Stack<t>::Stack( const Stack<t>& source ) : top( std::move( source.top ) ) {
	std::cout << "Stack copied : " << count << std::endl;
	}

template<typename t>
Stack<t>::Stack( Stack<t>&& source ) : top( std::move( source.top ) ) {
	std::cout << "Stack moved : " << ++count << std::endl;
	}

template<typename t>
Stack<t>::~Stack( ) {
	std::cout << "Stack destroyed : " << --count << std::endl;
	}

template<typename t>
void Stack<t>::display( ) const {
	if( this->top != nullptr ) {
		this->top->displayMe( );
		}
	}

template<typename t>
void Stack<t>::push( t value ) {
	std::unique_ptr<Node<t>> temp = std::make_unique<Node<t>>( value );
	if( this->top == nullptr ) {
		this->top = std::move( temp );
		}
	else {
		temp->setNext( std::move( this->top ) );
		this->top = std::move( temp );
		}
	}

template<typename t>
Node<t> Stack<t>::pop( ) {
	if( this->top != nullptr ) {
		auto temp = this->top->getData( );
		this->top = std::move( this->top->getNext( ) );
		return temp;
		}
	}


