#include "RBST.h"
#include <iostream>
#include <ostream>



int main( ) {

	RBST<int> bst( 6 );
	bst.display( );
	bst.insert( 8 );
	bst.insert( 3 );
	bst.insert( 10 );
	bst.display( );
	bst.insert( 1 );
	bst.insert( 5 );
	bst.insert( 14 );
	bst.display( );
	bst.insert( 4 );
	bst.insert( 7 );
	bst.insert( 9 );
	bst.insert( 5 );
	bst.display( );

	std::cout << bst.isin( 5 ) << std::endl;
	std::cout << bst.isin( 11 ) << std::endl;

	bst.remove( 5 );
	bst.display( );

	bst.remove( 3 );
	bst.display( );

	bst.remove( 6 );
	bst.display( );



	return 0;

	}