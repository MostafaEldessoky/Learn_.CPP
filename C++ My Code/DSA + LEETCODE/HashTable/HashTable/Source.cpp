#include"HT.h"
#include <iostream>
#include <string>

int main( ) {


	HT<std::string , int , 29> table;

	table.set( "mostafa" , 100 );
	table.set( "mohamed" , 200 );
	table.set( "eman" , 300 );
	table.set( "eldesouky" , 400 );
	table.set( "tafamos" , 500 );

	std::cout << table.get( "mohamed" ).value( ).getData( ) << std::endl;
	std::cout << table.get( "eman" ).value( ).getData( ) << std::endl;
	std::cout << table.get( "mostafa" ).value( ).getData( ) << std::endl;
	std::cout << table.get( "eldesouky" ).value( ).getData( ) << std::endl;
	std::cout << table.get( "tafamos" ).value( ).getData( ) << std::endl;
	if( table.get( "mohamed" ) ) {
		std::cout << table.get( "mohamed" ).value( ).getData( ) << std::endl;
		}

	return 0;
	}