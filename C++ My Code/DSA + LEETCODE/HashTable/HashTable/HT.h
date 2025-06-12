#pragma once
#include "Node.h"
#include <array>
#include <memory>
#include <optional>


template<typename t0 , typename t1 , int n>
class HT {

public:

	HT( );

	void set( t0 , t1 );
	std::optional<Node<t0 , t1>> get( t0 );

private:

	int hash_func( t0 );
	std::array<std::shared_ptr<Node<t0 , t1>> , n> hash_table;

	};

template<typename t0 , typename t1 , int n>
inline HT<t0 , t1 , n>::HT( ) {
	hash_table.fill( nullptr );
	}

template<typename t0 , typename t1 , int n>
inline void HT<t0 , t1 , n>::set( t0 key , t1 data ) {
	int index = hash_func( key );
	if( hash_table[index] == nullptr ) {
		hash_table[index] = std::make_shared<Node<t0 , t1>>( key , data );
		}
	else {
		auto temp = std::make_shared<Node<t0 , t1>>( key , data );
		temp->setNext( hash_table[index] );
		hash_table[index] = temp;
		}
	}

template<typename t0 , typename t1 , int n>
inline std::optional<Node<t0 , t1>> HT<t0 , t1 , n>::get( t0 key ) {
	int index = hash_func( key );
	if( hash_table[index] != nullptr ) {
		if( hash_table[index]->getKey( ) == key ) {
			auto temp = hash_table[index];
			hash_table[index] = hash_table[index]->getNext( );
			temp->setNext( nullptr );
			return *temp;
			}
		else {
			auto temp = hash_table[index];
			auto slow = temp;
			while( temp != nullptr ) {
				if( temp->getKey( ) == key ) {
					slow->setNext( temp->getNext( ) );
					temp->setNext( nullptr );
					return *temp;
					}
				slow = temp;
				temp = temp->getNext( );
				}
			}
		}
	return std::nullopt;
	}

template<typename t0 , typename t1 , int n>
inline int HT<t0 , t1 , n>::hash_func( t0 key ) {
	int temp = 0;
	for( auto c : key ) {
		temp = temp + ( int ) c;
		}
	temp = temp % n;
	return temp;
	}
