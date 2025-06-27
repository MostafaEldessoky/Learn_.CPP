#include <array>
#include "Matrix.h"


int main () {
	std::vector< std::vector< int > >* vec = new std::vector< std::vector< int > >{ { { 1 , 2 , 3 } , { 4 , 5 , 6 } } };

	std::vector< std::vector< int > >* vec2 = new std::vector< std::vector< int > >{ { 1 } , { 2 } , { 3 } };


	matrix< int > mtx( std::move( vec ) );

	matrix< int > mtx2( std::move( vec2 ) );

	auto y = mtx.transpose();

	y.display();

	auto y2 = mtx2.transpose();

	y2.display();

	auto x = ( mtx * mtx2 ).value();

	x.display();

	std::cout << vec << " " << vec2 << std::endl;

	return 0;
}
