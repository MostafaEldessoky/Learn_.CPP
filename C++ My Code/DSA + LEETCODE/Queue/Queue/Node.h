#pragma once
#include <iostream>
#include <memory>
#include <ostream>

template <typename t>
class Node {

public:

	Node( t );
	~Node( );

	t getData( ) const;
	std::shared_ptr<Node<t>> getNext( ) const;
	void setNext( std::shared_ptr<Node<t>> );
	void displayMe( ) const;

private:

	static int count;
	t data;
	std::shared_ptr<Node<t>> next;

	};

template<typename t>
int Node<t>::count = 0;

template<typename t>
inline Node<t>::Node( t data ) : data( data ) , next( nullptr ) {
	std::cout << "Node created count is : " << ++count << std::endl;
	}

template<typename t>
inline Node<t>::~Node( ) {
	std::cout << "Node destroyed count is : " << --count << std::endl;
	}

template<typename t>
inline t Node<t>::getData( ) const {
	return this->data;
	}

template<typename t>
inline std::shared_ptr<Node<t>> Node<t>::getNext( ) const {
	return this->next;
	}

template<typename t>
inline void Node<t>::setNext( std::shared_ptr<Node<t>> next ) {
	this->next = next;
	}

template<typename t>
inline void Node<t>::displayMe( ) const {
	std::cout << "Node data : " << this->data << " Next Node : " << this->next << std::endl;
	}
