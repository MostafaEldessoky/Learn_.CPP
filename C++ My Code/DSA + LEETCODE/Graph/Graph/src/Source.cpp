#include "Graph.h"
#include <string>

int main( ) {

	Graph<std::string> graph;
	std::string a = "hello";

	graph.addVertex( &a );
	graph.addVertex( &a );
	graph.display( );

	std::string b = "hi";
	graph.addVertex( &b );
	graph.display( );

	std::string c = "byby";
	graph.addVertex( &c );
	graph.display( );

	graph.addEdge( &a , &c );
	graph.addEdge( &a , &b );
	graph.display( );

	graph.removeEdge( &a , &c );
	graph.display( );
	graph.removeVertex( &b );
	graph.display( );

	return 0;
	}