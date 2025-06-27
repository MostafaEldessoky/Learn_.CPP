#include "Feach.h"


int main () {

	std::mutex mutex_;

	std::vector< int > v( 1000000 , 0 );

	int y = 0;

	forEach( v.begin() , v.end() , [&y] ( auto& x ) {
		y += x + 1;
		x = y;
	} );

	std::for_each( v.begin() , v.end() , [&y] ( auto& x ) {
		y += x + 1;
		x = y;
	} );

	// forEach( v.begin() , v.end() , [] ( auto& x ) {
	// 	++x;
	// } );


	// forEach( v.begin() , v.end() , [&mutex_] ( const auto& x ) {
	// 	mutex_.lock();
	// 	std::cout << x << " ";
	// 	mutex_.unlock();
	// } );


	return 0;
}
