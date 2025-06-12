#include "Quick.h"


int main( ) {

	Quick<int , 7> q1( 4 , 6 , 1 , 7 , 3 , 2 , 5 );
	q1.sort( );
	q1.display( );

	Quick<int , 8> q2( 5 , 1 , 2 , 6 , 7 , 3 , 8 , 4 );
	q2.sort( );
	q2.display( );

	Quick<int , 8> q3( 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 );
	q3.sort( );
	q3.display( );

	return 0;
	}