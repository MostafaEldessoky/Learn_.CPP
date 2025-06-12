#include <iostream>



inline int Factorial( unsigned long long );


int main( ) {

	unsigned long long x;

	std::cout << "enter number you need to compute its factorial : ";
	std::cin >> x;
	std::cout << "Factorial of " << x << " is : " << Factorial( x ) << std::endl;

	return 0;
	}


inline int Factorial( unsigned long long x ) {

	if( x == 1 || x == 0 ) {
		return 1;
		}
	else {
		x = x * Factorial( x - 1 );
		return x;
		}
	}