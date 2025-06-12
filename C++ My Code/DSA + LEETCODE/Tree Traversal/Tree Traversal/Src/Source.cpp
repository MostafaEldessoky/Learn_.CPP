#include "Tree.h"



int main( ) {

	Tree<int> bst( 47 );

	bst.insert( 21 );
	bst.insert( 76 );
	bst.insert( 18 );
	bst.insert( 27 );
	bst.insert( 52 );
	bst.insert( 82 );


	bst.displayBFS( );
	bst.displayPreOrder( );
	bst.displayPostOrder( );
	bst.displayInOrder( );



	return 0;

	}