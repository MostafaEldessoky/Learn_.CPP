#pragma once
#include <iostream>
#include <vector>

template<typename t>
class Heap {

	std::vector<t> heap;

public:

	Heap( t base ) {
		this->heap.push_back( base );
		};

	void display( );
	void insert( t );
	t remove( );

	};

template<typename t>
inline void Heap<t>::display( ) {
	for( const t& i : this->heap ) {
		std::cout << i << " ";
		}
	std::cout << std::endl;
	}

template<typename t>
inline void Heap<t>::insert( t data ) {

	this->heap.push_back( data );
	int temp1 = ( this->heap.size( ) - 1 ) / 2;
	int temp2 = this->heap.size( ) - 1;
	while( true ) {
		if( temp2 == 1 ) {
			break;
			}
		else if( temp2 % 2 == 0 ) {
			if( this->heap.at( temp2 ) > this->heap.at( temp1 ) ) {
				this->heap.at( temp2 ) = this->heap.at( temp1 );
				this->heap.at( temp1 ) = data;
				temp2 = temp1;
				temp1 = temp1 / 2;
				if( temp2 == 1 ) {
					break;
					}
				}
			else {
				break;
				}
			}
		else {
			if( this->heap.at( temp2 ) > this->heap.at( temp1 ) ) {
				this->heap.at( temp2 ) = this->heap.at( temp1 );
				this->heap.at( temp1 ) = data;
				temp2 = temp1;
				temp1 = temp1 / 2;
				if( temp2 == 1 ) {
					break;
					}
				}
			else {
				break;
				}
			}
		}

	}

template<typename t>
inline t Heap<t>::remove( ) {

	if( this->heap.size( ) > 1 ) {

		t data { this->heap.at( 1 ) };
		this->heap.at( 1 ) = this->heap.at( this->heap.size( ) - 1 );
		this->heap.pop_back( );

		int temp1 = 1; int temp2 = 0; int temp3 = 0;
		t temp;

		while( true ) {

			temp2 = 2 * temp1;
			temp3 = 2 * temp1 + 1;

			if( temp2 > this->heap.size( ) - 1 ) {
				break;
				}
			if( temp3 > this->heap.size( ) - 1 ) {
				if( this->heap.at( temp2 ) > this->heap.at( temp1 ) ) {
					temp = this->heap.at( temp2 );
					this->heap.at( temp2 ) = this->heap.at( temp1 );
					this->heap.at( temp1 ) = temp;
					temp1 = temp2;
					if( temp1 == this->heap.size( ) - 1 ) {
						break;
						}
					}
				else {
					break;
					}
				}
			else {
				if( this->heap.at( temp2 ) >= this->heap.at( temp3 ) ) {
					if( this->heap.at( temp2 ) > this->heap.at( temp1 ) ) {
						temp = this->heap.at( temp2 );
						this->heap.at( temp2 ) = this->heap.at( temp1 );
						this->heap.at( temp1 ) = temp;
						temp1 = temp2;
						if( temp1 == this->heap.size( ) - 1 ) {
							break;
							}
						}
					else {
						break;
						}
					}
				else {
					if( this->heap.at( temp3 ) > this->heap.at( temp1 ) ) {
						temp = this->heap.at( temp3 );
						this->heap.at( temp3 ) = this->heap.at( temp1 );
						this->heap.at( temp1 ) = temp;
						temp1 = temp3;
						if( temp1 == this->heap.size( ) - 1 ) {
							break;
							}
						}
					else {
						break;
						}
					}
				}
			}
		return data;
		}
	}
