#pragma once
#include <array>

class FibonacciSequence {

	std::array<int , 100> arr_;

public:

	int counter;

	FibonacciSequence( ) {
		arr_.fill( -1 );
		arr_[0] = 0;
		arr_[1] = 1;
		arr_[2] = 1;
		counter = 0;
		}

	int recursive_fibonacci_sequence( int x );
	int recursive_memoization_fibonacci_sequence( int x );
	int looping_fibonacci_sequence( int x );


	};


inline int FibonacciSequence::recursive_fibonacci_sequence( int x ) {
	this->counter++;
	if( x == 1 || x == 0 ) {
		return x;
		}
	return recursive_fibonacci_sequence( x - 1 ) + recursive_fibonacci_sequence( x - 2 );
	}

inline int FibonacciSequence::recursive_memoization_fibonacci_sequence( int x ) {
	this->counter++;
	if( this->arr_[x] != -1 ) {
		return this->arr_[x];
		}
	if( x == 1 || x == 0 ) {
		return 1;
		}
	this->arr_[x] = recursive_memoization_fibonacci_sequence( x - 1 ) + recursive_memoization_fibonacci_sequence( x - 2 );
	return this->arr_[x];
	}

inline int FibonacciSequence::looping_fibonacci_sequence( int x ) {
	for( int i = 1; i <= x; i++ ) {
		this->arr_[i + 2] = this->arr_[i] + this->arr_[i + 1];
		this->counter++;
		}
	return this->arr_[x];
	}

