#pragma once
#include <iostream>
#include <memory>
#include <ostream>

template <typename t>
class Node {
public:

	Node( t data );
	Node( const Node<t>& source );
	Node( Node<t>&& source ) noexcept;
	~Node( );

	void displayMe( ) const;
	void setData( t data );
	t getData( ) const;
	void setNext( std::unique_ptr<Node<t>> nextNode );
	std::unique_ptr<Node<t>> getNext( );

private:
	static int count;
	t data;
	std::unique_ptr<Node<t>> nextNode;
	};


template <typename t>
int Node<t>::count = 0;

template <typename t>
Node<t>::Node( t data ) : data( data ) , nextNode( nullptr ) {
	std::cout << "Node created. Current count : " << ++count << std::endl;
	}

template<typename t>
Node<t>::Node( const Node<t>& source ) : data( source.data ) , nextNode( std::move( source.nextNode ) ) {
	delete& source;
	std::cout << "Node copied. Current count : " << count << std::endl;
	}

template<typename t>
Node<t>::Node( Node<t>&& source ) noexcept : data( source.data ) , nextNode( std::move( source.nextNode ) ) {
	std::cout << "Node moved. Current count : " << ++count << std::endl;
	}

template <typename t>
Node<t>::~Node( ) {
	std::cout << "Node destroyed. Current count : " << --count << std::endl;
	}

template<typename t>
void Node<t>::displayMe( ) const {
	std::cout << "Data : " << this->data << " Next Node : " << this->nextNode << std::endl;
	}

template<typename t>
void Node<t>::setData( t data ) {
	this->data = data;
	}

template<typename t>
t Node<t>::getData( ) const {
	return this->data;
	}

template<typename t>
std::unique_ptr<Node<t>> Node<t>::getNext( ) {
	return std::move( this->nextNode );
	}

template<typename t>
void Node<t>::setNext( std::unique_ptr<Node<t>> nextNode ) {
	this->nextNode = std::move( nextNode );
	}

