#include "Queue.h"
#include <iostream>

int main( ) {

	Queue<int> q;

	q.enqueue( 1 );
	q.enqueue( 2 );
	q.enqueue( 3 );
	q.enqueue( 4 );
	q.enqueue( 5 );
	q.display( );
	std::cout << q.dequeue( ).getData( ) << std::endl;
	q.display( );
	std::cout << q.dequeue( ).getData( ) << std::endl;
	q.display( );
	std::cout << q.dequeue( ).getData( ) << std::endl;
	q.display( );
	std::cout << q.dequeue( ).getData( ) << std::endl;
	q.display( );
	std::cout << q.dequeue( ).getData( ) << std::endl;
	q.display( );
	std::cout << q.dequeue( ).getData( ) << std::endl;
	q.display( );


	return 0;
	}