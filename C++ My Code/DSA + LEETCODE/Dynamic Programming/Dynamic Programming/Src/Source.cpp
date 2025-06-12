#include "FibonacciSequence.h"
#include <iostream>

int main( ) {

	FibonacciSequence fibo1;
	std::cout << "Value : " << fibo1.looping_fibonacci_sequence( 7 ) << " number of operations of looping_fibonacci_sequence : " << fibo1.counter << std::endl;
	FibonacciSequence fibo2;
	std::cout << "Value : " << fibo2.recursive_fibonacci_sequence( 7 ) << " number of operations of recursive_fibonacci_sequence : " << fibo2.counter << std::endl;
	FibonacciSequence fibo3;
	std::cout << "Value : " << fibo3.recursive_memoization_fibonacci_sequence( 7 ) << " number of operations of recursive_memoization_fibonacci_sequence : " << fibo3.counter << std::endl;

	return 0;
	}



