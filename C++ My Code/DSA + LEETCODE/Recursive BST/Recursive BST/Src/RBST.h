#pragma once
#include "Node.h"
#include <iostream>
#include <memory>
#include <vector>

template <typename t>
class RBST {

public:

	RBST( t );
	~RBST( );

	void display( ) const;
	void insert( t data );
	void remove( t );
	bool isin( t ) const;

private:

	void insert( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp , bool isleft );
	bool isin( t data , std::shared_ptr<Node<t>> temp ) const;
	void remove( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp );
	t getMin( std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp );

	int static count;
	std::shared_ptr<Node<t>> root;

	};

template<typename t>
int RBST<t>::count = 0;

template<typename t>
inline RBST<t>::RBST( t data ) : root( std::make_shared<Node<t>>( data ) ) {
	std::cout << "RBST created count is : " << ++count << std::endl;
	}

template<typename t>
inline RBST<t>::~RBST( ) {
	std::cout << "RBST destroyed count is : " << --count << std::endl;
	}

template<typename t>
inline void RBST<t>::display( ) const {
	std::vector<std::vector<std::shared_ptr<Node<t>>>> nodes;
	if( this->root == nullptr ) {
		std::cout << "Tree is empty." << std::endl;
		return;
		}

	nodes.push_back( std::vector<std::shared_ptr<Node<t>>>{ this->root } );
	std::cout << this->root->getData( ) << std::endl;

	for( int i = 0; i < nodes.size( ); i++ ) {
		nodes.push_back( std::vector<std::shared_ptr<Node<t>>>( ) );
		int a = 0;
		int b = 0;
		for( auto j : nodes[i] ) {
			if( j->getLeft( ) != nullptr ) {
				nodes.at( i + 1 ).push_back( j->getLeft( ) );
				std::cout << j->getLeft( )->getData( ) << " ";
				a++;
				}

			if( j->getRight( ) != nullptr ) {
				nodes.at( i + 1 ).push_back( j->getRight( ) );
				std::cout << j->getRight( )->getData( ) << " ";
				b++;
				}
			}
		std::cout << std::endl;
		if( a == 0 && b == 0 ) {
			break;
			}
		}
	}


template<typename t>
inline void RBST<t>::insert( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp , bool isleft ) {

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
inline void RBST<t>::insert( t data ) {
	this->insert( data , this->root , this->root , true );
	}

template<typename t>
inline void RBST<t>::remove( t data , std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp ) {
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
inline void RBST<t>::remove( t data ) {
	this->remove( data , this->root , this->root );
	}

template<typename t>
inline t RBST<t>::getMin( std::shared_ptr<Node<t>> temp , std::shared_ptr<Node<t>> roottemp ) {

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
inline bool RBST<t>::isin( t data , std::shared_ptr<Node<t>> temp ) const {
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
inline bool RBST<t>::isin( t data ) const {
	return this->isin( data , this->root );
	}


