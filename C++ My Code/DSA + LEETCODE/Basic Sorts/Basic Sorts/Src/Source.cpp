#include "Sort.h"

int main( ) {
	sort<int , 5> s1 { 2 , 3 , 4 , 1 , 5 };
	s1.bubble_sort( );
	s1.display( );

	sort<int , 9> s2 { 2 , 3 , 4 , 1 , 5 , 11 , 0 , -1 , -4 };
	s2.selection_sort( );
	s2.display( );

	sort<int , 7> s3 { 2 , 3 , 41 , 1 , 5 , 17 , -100 };
	s3.insertion_sort( );
	s3.display( );

	return 0;
	}