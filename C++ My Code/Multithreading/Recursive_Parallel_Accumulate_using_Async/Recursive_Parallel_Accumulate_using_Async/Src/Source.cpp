#include "Acc.h"
#include <vector>
#include <iostream>
#include <numeric>


int main () {

	std::vector< int > data( 1000000 );
	std::iota( data.begin() , data.end() , 0 );
	int value1 = Acc< std::vector< int >::iterator , int >( data.begin() , data.end() , 1 );
	int value2 = std::accumulate( data.begin() , data.end() , 1 );
	std::cout << value1 << " " << value2 << std::endl;

	return 0;
}
