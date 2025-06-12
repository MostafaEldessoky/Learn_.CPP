#include "Stack.h"
#include <iostream>

int main( ) {

	Stack<int> stack;

	stack.push( 1 );
	stack.push( 2 );
	stack.push( 3 );
	stack.push( 4 );
	stack.display( );
	stack.pop( );
	stack.display( );
	stack.pop( );
	stack.display( );
	stack.pop( );
	stack.display( );
	stack.pop( );
	stack.display( );

	std::cout << "the end" << std::endl;

	return 0;
	}