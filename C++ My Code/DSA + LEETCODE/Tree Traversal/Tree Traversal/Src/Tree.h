#pragma once
#include "Node.h"
#include <iostream>
#include <memory>
#include <queue>

template <typename t>
class Tree {

public:

	Tree( t );
	~Tree( );

	void displayBFS( ) const;
	void displayPreOrder( ) const;
	void displayPostOrder( ) const;
	void displayInOrder( ) const;
	void insert( t data );
	void remove( t );
	bool isin( t ) const;

private:

	void displayPreOrder( std::shared_ptr<Node<t>>  root ) const;
	void displayPostOrder( std::shared_ptr<Node<t>> root ) const;
	void displayInOrder( std::shared_ptr<Node<t>> root ) const;

	void insert( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp , bool isleft );
	bool isin( t data , std::shared_ptr<Node<t>> temp ) const;
	void remove( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp );
	t getMin( std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp );

	int static count;
	std::shared_ptr<Node<t>> root;

	};

template<typename t>
int Tree<t>::count = 0;

template<typename t>
inline Tree<t>::Tree( t data ) : root( std::make_shared<Node<t>>( data ) ) {
	std::cout << "Tree created count is : " << ++count << std::endl;
	}

template<typename t>
inline Tree<t>::~Tree( ) {
	std::cout << "Tree destroyed count is : " << --count << std::endl;
	}

template<typename t>
inline void Tree<t>::displayBFS( ) const {
	std::queue<std::shared_ptr<Node<t>>> nodes;
	nodes.push( this->root );
	while( !nodes.empty( ) ) {
		auto ptr = nodes.front( );
		nodes.pop( );
		std::cout << ptr->getData( ) << " ";
		if( ptr->getLeft( ) != nullptr ) {
			nodes.push( ptr->getLeft( ) );
			}
		if( ptr->getRight( ) != nullptr ) {
			nodes.push( ptr->getRight( ) );
			}
		}
	std::cout << std::endl;
	}

template<typename t>
inline void Tree<t>::displayPreOrder( std::shared_ptr<Node<t>> root ) const {
	auto ptr = root;
	std::cout << ptr->getData( ) << " ";
	if( ptr->getLeft( ) != nullptr ) {
		this->displayPreOrder( ptr->getLeft( ) );
		}
	if( ptr->getRight( ) != nullptr ) {
		this->displayPreOrder( ptr->getRight( ) );
		}
	}

template<typename t>
inline void Tree<t>::displayPreOrder( ) const {
	this->displayPreOrder( this->root );
	std::cout << std::endl;
	}

template<typename t>
inline void Tree<t>::displayPostOrder( std::shared_ptr<Node<t>> root ) const {
	if( root->getLeft( ) != nullptr ) {
		this->displayPostOrder( root->getLeft( ) );
		if( root->getRight( ) != nullptr ) {
			this->displayPostOrder( root->getRight( ) );
			}
		std::cout << root->getData( ) << " ";
		}
	else {
		std::cout << root->getData( ) << " ";
		}
	}

template<typename t>
inline void Tree<t>::displayPostOrder( ) const {
	this->displayPostOrder( this->root );
	std::cout << std::endl;
	}

template<typename t>
inline void Tree<t>::displayInOrder( std::shared_ptr<Node<t>> root ) const {
	if( root->getLeft( ) != nullptr ) {
		this->displayInOrder( root->getLeft( ) );
		std::cout << root->getData( ) << " ";
		if( root->getRight( ) != nullptr ) {
			this->displayInOrder( root->getRight( ) );
			}
		}
	else {
		std::cout << root->getData( ) << " ";
		}
	}

template<typename t>
inline void Tree<t>::displayInOrder( ) const {
	this->displayInOrder( this->root );
	std::cout << std::endl;
	}

template<typename t>
inline void Tree<t>::insert( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp , bool isleft ) {

	if( temp == nullptr ) {
		temp = std::make_shared<Node<t>>( data );
		if( isleft ) {
			roottemp->setLeft( temp );
			}
		else {
			roottemp->setRight( temp );
			}
		return;
		}
	if( temp->getData( ) == data ) {
		std::cout << "Data already exists in the tree." << std::endl;
		return;
		}
	else if( temp->getData( ) < data ) {
		roottemp = temp;
		isleft = false;
		temp = temp->getRight( );
		this->insert( data , temp , roottemp , isleft );
		}
	else {
		roottemp = temp;
		isleft = true;
		temp = temp->getLeft( );
		this->insert( data , temp , roottemp , isleft );
		}
	}

template<typename t>
inline void Tree<t>::insert( t data ) {
	this->insert( data , this->root , this->root , true );
	}

template<typename t>
inline void Tree<t>::remove( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp ) {
	bool isleft;
	if( temp == nullptr ) {
		std::cout << data << " is not in the tree " << std::endl;
		return;
		}
	if( temp->getData( ) < data ) {
		temp = temp->getRight( );
		isleft = false;
		}
	else if( temp->getData( ) > data ) {
		temp = temp->getLeft( );
		isleft = true;
		}
	if( temp->getData( ) == data ) {
		if( temp->getLeft( ) == nullptr && temp->getRight( ) == nullptr ) {
			if( isleft ) {
				roottemp->setLeft( nullptr );
				temp.reset( );
				return;
				}
			else {
				roottemp->setRight( nullptr );
				temp.reset( );
				return;
				}
			}
		else if( temp->getLeft( ) == nullptr ) {
			if( isleft ) {
				roottemp->setLeft( temp->getRight( ) );
				temp->setRight( nullptr );
				temp.reset( );
				return;
				}
			else {
				roottemp->setRight( temp->getRight( ) );
				temp->setRight( nullptr );
				temp.reset( );
				return;
				}
			}
		else if( temp->getRight( ) == nullptr ) {
			if( isleft ) {
				roottemp->setLeft( temp->getLeft( ) );
				temp->setLeft( nullptr );
				temp.reset( );
				return;
				}
			else {
				roottemp->setRight( temp->getLeft( ) );
				temp->setLeft( nullptr );
				temp.reset( );
				return;
				}
			}
		else {
			temp->setData( this->getMin( temp->getRight( ) , temp->getRight( ) ) );
			return;
			}
		}
	else {
		roottemp = temp;
		this->remove( data , temp , roottemp );
		}
	}

template<typename t>
inline void Tree<t>::remove( t data ) {
	this->remove( data , this->root , this->root );
	}

template<typename t>
inline t Tree<t>::getMin( std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp ) {

	if( temp->getLeft( ) == nullptr ) {
		auto value = temp->getData( );
		roottemp->setLeft( nullptr );
		temp.reset( );
		return value;
		}
	else {
		roottemp = temp;
		temp = temp->getLeft( );
		return this->getMin( temp , roottemp );
		}

	}

template<typename t>
inline bool Tree<t>::isin( t data , std::shared_ptr<Node<t>> temp ) const {
	if( temp == nullptr ) {
		return false;
		}
	if( temp->getData( ) == data ) {
		return true;
		}
	else if( temp->getData( ) < data ) {
		temp = temp->getRight( );
		return this->isin( data , temp );
		}
	else {
		temp = temp->getLeft( );
		return this->isin( data , temp );
		}
	}

template<typename t>
inline bool Tree<t>::isin( t data ) const {
	return this->isin( data , this->root );
	}
