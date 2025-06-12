#pragma once
#include <iostream>
#include<memory>

template<typename t>
class Node {

public:

	Node( t );
	~Node( );

	void displayMe( ) const;
	t getData( ) const;
	void setData( t );
	std::shared_ptr<Node<t>> getLeft( ) const;
	std::shared_ptr<Node<t>> getRight( ) const;
	void setLeft( std::shared_ptr<Node<t>> left );
	void setRight( std::shared_ptr<Node<t>> right );

private:

	static int nodeCount;
	t data;
	std::shared_ptr<Node<t>> left;
	std::shared_ptr<Node<t>> right;

	};

template<typename t>
int Node<t>::nodeCount = 0;

template<typename t>
inline Node<t>::Node( t data ) : data( data ) , left( nullptr ) , right( nullptr ) {
	std::cout << "Node created count now is : " << ++nodeCount << std::endl;
	}

template<typename t>
inline Node<t>::~Node( ) {
	std::cout << "Node destroyed count now is : " << --nodeCount << std::endl;
	}

template<typename t>
inline void Node<t>::displayMe( ) const {
	std::cout << "Node data: " << data << " my left : " << this->left << " my right : " << this->right << std::endl;
	}

template<typename t>
inline t Node<t>::getData( ) const {
	return this->data;
	}

template<typename t>
inline void Node<t>::setData( t data ) {
	this->data = data;
	}

template<typename t>
inline std::shared_ptr<Node<t>> Node<t>::getLeft( ) const {
	return this->left;
	}

template<typename t>
inline std::shared_ptr<Node<t>> Node<t>::getRight( ) const {
	return this->right;
	}

template<typename t>
inline void Node<t>::setLeft( std::shared_ptr<Node<t>> left ) {
	this->left = left;
	}

template<typename t>
inline void Node<t>::setRight( std::shared_ptr<Node<t>> right ) {
	this->right = right;
	}




