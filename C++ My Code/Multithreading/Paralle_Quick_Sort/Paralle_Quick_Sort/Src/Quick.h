#pragma once
#include <array>
#include <future>
#include <iostream>


template < typename T , int N >
class Quick {

	std::array< T , N > array_;

	std::array< T , N > pivoit ( int , int , bool left = true );


	public:

		template < typename... Args >
		Quick ( Args... );

		std::array< T , N > sort ();

		void display ();

};


template < typename T , int N >
std::array< T , N > Quick< T , N >::pivoit ( int start , int end , bool left ) {
	int g1 = start;
	int g0 = start;
	int l1 = start;
	int i  = start + 1;
	do {
		if(this->array_[start] < this->array_[i]) {
			if(g0 == start) {
				g0 = i;
			}
			g1 = i;
		}
		else {
			l1 = i;
		}
		if(l1 != 0 && g1 != 0) {
			if(l1 > g1) {
				auto temp        = this->array_[l1];
				this->array_[l1] = this->array_[g0];
				this->array_[g0] = temp;
				g0++;
			}
		}
		if(i == end) {
			if(g0 == start) {
				g0 = end + 1;
			}
			auto temp            = this->array_[start];
			this->array_[start]  = this->array_[g0 - 1];
			this->array_[g0 - 1] = temp;
		}
		i++;
	}
	while(i <= end);
	if(g0 - 2 >= 1 && left == true) {
		std::async( std::launch::async , &Quick< T , N >::pivoit , this , 0 , g0 - 2 , true );
	}
	left = false;
	if(g0 <= this->array_.size() - 2 && left == false) {
		std::async( std::launch::async , &Quick< T , N >::pivoit , this , g0 , this->array_.size() - 1 , false );
	}
	return this->array_;
}


template < typename T , int N >
template < typename... Args >
Quick< T , N >::Quick ( Args... args ) : array_( { args... } ) {
}


template < typename T , int N >
std::array< T , N > Quick< T , N >::sort () {
	return this->pivoit( 0 , this->array_.size() - 1 );
}


template < typename T , int N >
void Quick< T , N >::display () {
	for(const auto& element : this->array_) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
