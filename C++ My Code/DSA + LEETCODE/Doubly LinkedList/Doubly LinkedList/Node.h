#pragma once
#include <iostream>

template<typename t>
class Node {
	static int count;
	t data;
	Node<t>* mynext;
	Node<t>* myprev;

public:
	Node( t data = 0 );
	Node( const Node<t>& );
	Node( Node<t>&& );
	~Node( );

	void displayMe( );
	t getData( );
	void setData( t );
	Node<t>* getMyNext( );
	void setMyNext( Node<t>* );
	Node<t>* getMyPrev( );
	void setMyPrev( Node<t>* );
	};


template<typename t>
int Node<t>::count = 0;

template<typename t>
Node<t>::Node( t data ) : data( data ) , myprev( nullptr ) , mynext( nullptr ) {
	count++;
	std::cout << "Node constractor called : " << count << std::endl;
	}

template<typename t>
Node<t>::Node( const Node<t>& source ) : data( source.data ) , myprev( source.myprev ) , mynext( source.mynext ) {
	std::cout << "Node copy constructor called" << std::endl;
	}

template<typename t>
Node<t>::Node( Node<t>&& source ) : data( source.data ) , myprev( source.myprev ) , mynext( source.mynext ) {
	count++;
	std::cout << "Node move constructor called : " << count << std::endl;
	source.myprev = nullptr;
	source.mynext = nullptr;
	}

template<typename t>
Node<t>::~Node( ) {
	count--;
	std::cout << "Node destructor called : " << count << std::endl;
	this->mynext = nullptr;
	this->myprev = nullptr;
	delete this->mynext;
	delete this->myprev;
	}

template<typename t>
void Node<t>::displayMe( ) {
	std::cout << "My data : " << this->data << " My Next : " << this->mynext
		<< " My Prev : " << this->myprev;
	}

template<typename t>
t Node<t>::getData( ) {
	return this->data;
	}

template<typename t>
void Node<t>::setData( t data ) {
	this->data = data;
	}

template<typename t>
Node<t>* Node<t>::getMyNext( ) {
	return this->mynext;
	}

template<typename t>
void Node<t>::setMyNext( Node<t>* next ) {
	this->mynext = next;
	}

template<typename t>
Node<t>* Node<t>::getMyPrev( ) {
	return this->myprev;
	}

template<typename t>
void Node<t>::setMyPrev( Node<t>* prev ) {
	this->myprev = prev;
	}



