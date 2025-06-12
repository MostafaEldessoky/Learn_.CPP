#pragma once
#include "Node.h"
#include <iostream>
#include <memory>
#include <vector>

template <typename t>
class BST {

public:

	BST( t );
	~BST( );

	void display( ) const;
	void insert( t );
	void remove( t );
	bool isin( t ) const;

private:

	int static count;
	std::shared_ptr<Node<t>> root;

	};

template<typename t>
int BST<t>::count = 0;

template<typename t>
inline BST<t>::BST( t data ) : root( std::make_shared<Node<t>>( data ) ) {
	std::cout << "BST created count is : " << ++count << std::endl;
	}

template<typename t>
inline BST<t>::~BST( ) {
	std::cout << "BST destroyed count is : " << --count << std::endl;
	}

template<typename t>
inline void BST<t>::display( ) const {
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
inline void BST<t>::insert( t data ) {
	auto roottemp = this->root;
	auto temp = this->root;
	bool isleft;
	while( true ) {
		if( temp->getData( ) == data ) {
			std::cout << "Data already exists in the tree." << std::endl;
			break;
			}
		else if( temp->getData( ) < data ) {
			roottemp = temp;
			isleft = false;
			temp = temp->getRight( );
			}
		else {
			roottemp = temp;
			isleft = true;
			temp = temp->getLeft( );
			}
		if( temp == nullptr ) {
			temp = std::make_shared<Node<t>>( data );
			if( isleft ) {
				roottemp->setLeft( temp );
				}
			else {
				roottemp->setRight( temp );
				}
			break;
			}
		}
	}
template<typename t>
inline void BST<t>::remove( t data ) {
	auto temp = this->root;
	auto roottemp = this->root;
	bool isleft;
	if( temp->getRight( ) == nullptr && temp->getLeft( ) == nullptr ) {
		this->root.reset( );
		std::cout << "Tree is empty." << std::endl;
		return;
		}
	while( temp != nullptr ) {
		if( temp->getData( ) == data ) {
			auto iter = temp;
			if( temp == this->root ) {
				if( temp->getRight( ) != nullptr ) {
					temp = temp->getRight( );
					iter = temp;
					while( iter->getLeft( ) != nullptr ) {
						iter = iter->getLeft( );
						}
					iter->setLeft( roottemp->getLeft( ) );
					}
				else {
					temp = temp->getLeft( );
					iter = temp;
					while( iter->getRight( ) != nullptr ) {
						iter = iter->getRight( );
						}
					iter->setRight( roottemp->getRight( ) );
					}
				this->root = temp;
				roottemp->setLeft( nullptr );
				roottemp->setRight( nullptr );
				roottemp.reset( );
				break;
				}
			iter = temp->getRight( );
			if( iter != nullptr ) {
				while( iter->getLeft( ) != nullptr ) {
					iter = iter->getLeft( );
					}
				iter->setLeft( temp->getLeft( ) );

				if( isleft ) {
					roottemp->setLeft( temp->getRight( ) );
					}
				else {
					roottemp->setRight( temp->getRight( ) );
					}
				}
			else {
				if( isleft ) {
					roottemp->setLeft( temp->getLeft( ) );
					}
				else {
					roottemp->setRight( temp->getLeft( ) );
					}
				}
			temp->setLeft( nullptr );
			temp->setRight( nullptr );
			temp.reset( );
			}
		else if( temp->getData( ) < data ) {
			roottemp = temp;
			isleft = false;
			temp = temp->getRight( );
			}
		else {
			roottemp = temp;
			isleft = true;
			temp = temp->getLeft( );
			}
		}

	}

template<typename t>
inline bool BST<t>::isin( t data ) const {
	bool is = false;
	auto temp = this->root;
	while( true ) {
		if( temp->getData( ) == data ) {
			is = true;
			break;
			}
		else if( temp->getData( ) < data ) {
			temp = temp->getRight( );
			}
		else {
			temp = temp->getLeft( );
			}
		if( temp == nullptr ) {
			break;
			}
		}
	return is;
	}
