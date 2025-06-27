#include <iostream>
#include <numeric>
#include "Find.h"


int main () {


	std::vector< int > v( 1000000 , 5 );
	std::iota( v.begin() , v.end() , 0 );

	auto y = PFind( v.begin() , v.end() , 5 );

	std::cout << "Found: " << *y << std::endl;


	return 0;
}
