#pragma once
#include <array>
#include <iostream>

template<typename T , int N>
class sort {

	std::array<T , N> block_;

public:

	template<typename ... Args>
	sort( Args... args );

	std::array<T , N>& bubble_sort( );
	std::array<T , N>& selection_sort( );
	std::array<T , N>& insertion_sort( );

	void display( )const;

	};

template<typename T , int N >
template<typename... Args>
sort<T , N>::sort( Args... args ) : block_( { args... } ) { }

template<typename T , int N>
std::array<T , N>& sort<T , N>::bubble_sort( ) {
	int k = this->block_.size( );
	for( int j = this->block_.size( ); j >= 1; --j ) {
		for( int i = 0; i <= this->block_.size( ) - 2; i++ ) {
			if( this->block_[i] > this->block_[i + 1] ) {
				auto temp = this->block_[i];
				this->block_[i] = this->block_[i + 1];
				this->block_[i + 1] = temp;
				}
			}
		}
	return this->block_;
	}

template <typename T , int N>
std::array<T , N>& sort<T , N>::selection_sort( ) {
	for( int i = this->block_.size( ) - 1; i >= 1; --i ) {
		int temp = this->block_.size( ) - 1 - i;
		for( int j = this->block_.size( ) - 1 - i; j <= this->block_.size( ) - 2; ++j ) {
			if( this->block_[j + 1] < this->block_[temp] ) {
				temp = j + 1;
				}
			}
		auto temp1 = this->block_[temp];
		this->block_[temp] = this->block_[this->block_.size( ) - 1 - i];
		this->block_[this->block_.size( ) - 1 - i] = temp1;
		}
	return this->block_;
	}

template <typename T , int N>
std::array<T , N>& sort<T , N>::insertion_sort( ) {
	for( int i = 1; i <= this->block_.size( ) - 1; ++i ) {
		int k = 0;
		for( int j = i - 1; j >= 0; --j ) {
			if( this->block_[i - k] < this->block_[j] ) {
				auto temp = this->block_[j];
				this->block_[j] = this->block_[i - k];
				this->block_[i - k] = temp;
				k++;
				}
			}
		}
	return this->block_;
	}

template <typename T , int N>
void sort<T , N>::display( ) const {
	for( const auto& element : this->block_ ) {
		std::cout << element << " ";
		}
	std::cout << std::endl;
	}