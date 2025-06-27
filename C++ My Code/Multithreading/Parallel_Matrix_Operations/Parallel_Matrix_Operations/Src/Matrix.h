#pragma once
#include <future>
#include <iostream>
#include <optional>


template < typename T >
class matrix {

	typedef std::vector< std::vector< T > >* vector_ptr;

	vector_ptr vector_;


	public:

		matrix ( vector_ptr&& );

		~matrix ();

		matrix ( const matrix& other );

		matrix ( matrix&& other ) noexcept;

		std::optional< matrix > operator* ( const matrix& other ) const;

		matrix transpose ();

		void display ();
};


template < typename T >
matrix< T >::matrix ( vector_ptr&& ptr ) : vector_( ptr ) {
	ptr = nullptr;
}


template < typename T >
matrix< T >::~matrix () {
	delete vector_;
}


template < typename T >
matrix< T >::matrix ( const matrix& other ) : vector_( new vector_ptr( *other.vector_ ) ) {
}


template < typename T >
matrix< T >::matrix ( matrix&& other ) noexcept : vector_( other.vector_ ) {
	other.vector_ = nullptr;
}


template < typename T >
std::optional< matrix< T > > matrix< T >::operator* ( const matrix& other ) const {
	if(vector_->at( 0 ).size() == other.vector_->size()) {
		vector_ptr output = new std::vector< std::vector< T > >( vector_->size() );
		for(auto& i : *output) {
			i.resize( other.vector_->at( 0 ).size() );
		}
		std::vector< std::future< void > > futures;
		for(int rows = 0 ; rows < vector_->size() ; rows++) {
			futures.push_back( std::async( std::launch::async , [rows, this, &other, &output] () {
				for(int j = 0 ; j < other.vector_->at( 0 ).size() ; j++) {
					for(int i = 0 ; i < vector_->at( 0 ).size() ; i++) {
						output->at( rows ).at( j ) += vector_->at( rows ).at( i ) * other.vector_->at( i ).at( j );
					}
				}
			} ) );
		}
		for(auto& future : futures) {
			future.wait();
		}
		return matrix( std::move( output ) );
	}
	return std::nullopt;
}


template < typename T >
matrix< T > matrix< T >::transpose () {
	vector_ptr output = new std::vector< std::vector< T > >( vector_->at( 0 ).size() );
	for(auto& i : *output) {
		i.resize( vector_->size() );
	}
	std::vector< std::future< void > > futures;
	for(int rows = 0 ; rows < vector_->size() ; rows++) {
		futures.push_back( std::async( std::launch::async , [rows, this, &output] () {
			for(int i = 0 ; i < vector_->at( 0 ).size() ; i++) {
				output->at( i ).at( rows ) = vector_->at( rows ).at( i );
			}
		} ) );
	}
	for(auto& future : futures) {
		future.wait();
	}
	return matrix( std::move( output ) );
}


template < typename T >
void matrix< T >::display () {
	for(const auto& rows : *vector_) {
		for(const auto& element : rows) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
}
