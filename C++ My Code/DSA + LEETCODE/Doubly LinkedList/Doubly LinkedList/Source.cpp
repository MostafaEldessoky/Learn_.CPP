#include "DLN.h"
#include "Node.h"
#include <iostream>

int main( ) {

	DLN<int> dln;
	dln.append( 1 );
	dln.append( 2 );
	dln.append( 3 );

	dln.display( );
	std::cout << "\n";

	dln.prepend( 6 );
	dln.prepend( 5 );
	dln.prepend( 4 );

	dln.display( );
	std::cout << "\n";


	dln.insert( 3 , 100 );
	dln.display( );
	std::cout << "\n";
	dln.insert( 0 , 500 );
	dln.display( );
	std::cout << "\n";
	dln.insert( 1 , 200 );
	dln.display( );
	std::cout << "\n";
	dln.insert( 5 , 300 );
	dln.display( );
	std::cout << "\n";

	dln.deleteNode( 0 );
	dln.display( );
	std::cout << "\n";
	dln.deleteNode( 8 );
	dln.display( );
	std::cout << "\n";
	dln.deleteNode( 4 );
	dln.display( );
	std::cout << "\n";
	dln.deleteNode( 5 );
	dln.display( );
	std::cout << "\n";
	dln.deleteNode( 1 );
	dln.display( );
	std::cout << "\n";

	dln.deleteFirst( );
	dln.deleteLast( );

	dln.display( );
	std::cout << "\n";

	dln.set( 2 , 11 );

	dln.display( );
	std::cout << "\n";

	dln.get( 1 ).displayMe( );
	std::cout << "\n";

	std::cout << "THE END";
	std::cout << "\n";

	return 0;
	}