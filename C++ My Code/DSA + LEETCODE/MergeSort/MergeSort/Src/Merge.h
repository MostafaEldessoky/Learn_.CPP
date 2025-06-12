#pragma once
#include <iostream>
#include <vector>


template <typename T>
class Merge {

	std::vector<T> vec_;

	std::vector<T> merge( std::vector<T> , std::vector<T> );

	std::vector<T> sort( std::vector<T> );

public:

	template <typename... Args>
	Merge( Args... );

	std::vector<T> sort( );

	void display( )const;

	};

template <typename T>
template <typename... Args>
Merge<T>::Merge( Args... args ) : vec_( { args... } ) { }


template <typename T>
std::vector<T> Merge<T>::merge( std::vector<T> arr1 , std::vector<T> arr2 ) {
	std::vector<T> arr;
	int i = 0;
	int j = 0;
	while( true ) {
		if( i == arr1.size( ) ) {
			for( j; j <= arr2.size( ) - 1; j++ ) {
				arr.push_back( arr2[j] );
				}
			break;
			}
		if( j == arr2.size( ) ) {
			for( i; i <= arr2.size( ) - 1; i++ ) {
				arr.push_back( arr1[i] );
				}
			break;
			}
		if( arr1[i] > arr2[j] ) {
			arr.push_back( arr2[j] );
			j++;
			}
		else {
			arr.push_back( arr1[i] );
			i++;
			}
		}
	return arr;
	}

template <typename T>
std::vector<T> Merge<T>::sort( std::vector<T> vec ) {
	if( vec.size( ) == 1 ) {
		return vec;
		}
	std::vector<T> vec1( vec.begin( ) , vec.begin( ) + ( vec.size( ) / 2 ) ) , vec2( vec.begin( ) + ( vec.size( ) / 2 ) , vec.end( ) );
	return this->merge( this->sort( vec1 ) , this->sort( vec2 ) );
	}

template <typename T>
std::vector<T> Merge<T>::sort( ) {
	this->vec_ = this->sort( this->vec_ );
	return this->vec_;
	}

template <typename T>
void Merge<T>::display( ) const {
	for( const auto& element : this->vec_ ) {
		std::cout << element << " ";
		}
	std::cout << std::endl;
	}
