#pragma once
#include <iostream>
#include<map>
#include <ostream>
#include <set>


template<typename t>
class Graph {

public:

	Graph( ) = default;

	Graph<t>& addVertex( t* vertex );
	Graph<t>& addEdge( t* vertex , t* edge );
	Graph<t>& removeVertex( t* vertex );
	Graph<t>& removeEdge( t* vertex , t* edge );

	void display( );


private:

	std::map<t* , std::set<t*>> adjSet;

	};


template<typename t>
inline Graph<t>& Graph<t>::addVertex( t* vertex ) {

	if( this->adjSet.count( vertex ) == 0 ) {
		this->adjSet.insert( { vertex, {} } );
		}
	else {
		std::cout << "this vertex already exist" << std::endl;
		}

	return *this;

	}

template<typename t>
inline Graph<t>& Graph<t>::addEdge( t* vertex , t* edge ) {

	if( this->adjSet.count( vertex ) == 1 && this->adjSet.count( edge ) == 1 ) {
		this->adjSet[vertex].insert( edge );
		this->adjSet[edge].insert( vertex );
		}
	else {
		std::cout << "vertex or edge not exist" << std::endl;
		}
	return *this;

	}

template<typename t>
inline Graph<t>& Graph<t>::removeVertex( t* vertex ) {

	if( this->adjSet.count( vertex ) == 1 ) {
		this->adjSet.erase( vertex );
		for( auto& i : this->adjSet ) {
			i.second.erase( vertex );
			}
		}
	else {
		std::cout << "vertex already not exist" << std::endl;
		}
	return *this;
	}

template<typename t>
inline Graph<t>& Graph<t>::removeEdge( t* vertex , t* edge ) {
	if( this->adjSet.count( vertex ) == 1 && this->adjSet.count( edge ) == 1 ) {
		this->adjSet[vertex].erase( edge );
		this->adjSet[edge].erase( vertex );
		}
	else {
		std::cout << "vertex or edge already not exist" << std::endl;
		}
	return *this;
	}

template<typename t>
inline void Graph<t>::display( ) {
	for( const auto& i : this->adjSet ) {
		std::cout << "Vertex : " << *( i.first ) << " Edges : ";
		for( const auto& j : i.second ) {
			std::cout << *j << " ";
			}
		std::cout << std::endl;
		}
	}
