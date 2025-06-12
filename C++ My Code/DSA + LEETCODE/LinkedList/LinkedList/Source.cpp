#include <iostream>

#include "Node.h"
#include <vector>

#include "LinkedNodes.h"

void fn( Node<int> g ) {
	g.displyMe( );
	}

int main( ) {
	Node<int> node1;
	Node<int> node2;
	node2 = node1;

	std::vector<Node<int>> vec;
	vec.push_back( Node<int>( 5 ) ); std::cout << "step 2" << std::endl;
	vec.push_back( Node<int>( 6 ) );

	fn( node1 );

	LinkNodes<int>* link = new LinkNodes<int>( );
	LinkNodes<int>* link2;

	link->Prepend( 0 );
	link->Prepend( -1 );
	link->Prepend( -2 );

	link->Append( 1 );
	link->Append( 2 );
	link->Append( 3 );

	link->display( );
	std::cout << std::endl;

	link->InsertNode( 2 , 100 );

	link->display( );
	std::cout << std::endl;

	link->DeleteNode( 1 );

	link->display( );
	std::cout << std::endl;

	link->DeleteFirst( );

	link->display( );
	std::cout << std::endl;

	link->DeleteLast( );

	link->display( );
	std::cout << std::endl;

	link->get( 2 ).displyMe( );
	std::cout << std::endl;

	link->display( );
	std::cout << std::endl;

	link->set( 2 , 10 );

	link->display( );
	std::cout << std::endl;

	link->Reverse( );

	link->display( );
	std::cout << std::endl;

	link2 = link;

	delete link;

	std::cout << "THE END" << std::endl;

	return 0;
	}
