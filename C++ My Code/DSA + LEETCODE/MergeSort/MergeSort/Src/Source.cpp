#include"Merge.h"

int main( ) {

	Merge<int> merge1( 2 , 5 , 1 , 6 , 4 , 8 , 3 );
	merge1.sort( );
	merge1.display( );


	Merge<int> merge2( 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 );
	merge2.sort( );
	merge2.display( );

	return 0;
	}

