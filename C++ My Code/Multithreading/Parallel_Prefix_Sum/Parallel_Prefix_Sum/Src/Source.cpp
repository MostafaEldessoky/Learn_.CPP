#include <iostream>
#include <vector>
#include "PrfixSum.h"


int main () {

	std::vector< int > input( 10000 , 1 );

	std::vector< int > result = prefix_sum( input.begin() , input.end() );

	std::for_each( result.begin() , result.end() , [] ( const int& x ) {
		std::cout << x << " ";
	} );

	return 0;
}
