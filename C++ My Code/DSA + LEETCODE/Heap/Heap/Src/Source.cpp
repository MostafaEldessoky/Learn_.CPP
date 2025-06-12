#include"Heap.h"



int main( ) {

	Heap<int> heap( 0 );

	heap.insert( 9 );
	heap.display( );

	heap.insert( 4 );
	heap.display( );

	heap.insert( 6 );
	heap.display( );

	heap.insert( 7 );
	heap.display( );

	heap.insert( 3 );
	heap.display( );

	heap.insert( 5 );
	heap.display( );

	heap.insert( 2 );
	heap.display( );

	heap.insert( 10 );
	heap.display( );

	heap.remove( );
	heap.display( );

	heap.remove( );
	heap.display( );

	heap.remove( );
	heap.display( );


	return 0;
	}