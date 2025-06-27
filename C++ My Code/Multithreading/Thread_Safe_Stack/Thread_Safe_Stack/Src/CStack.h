#pragma once
#include <mutex>
#include <optional>
#include "CNode.h"


template < typename T >
class c_stack {

	c_node< T >* top_;
	std::mutex   mutex_;


	public:

		c_stack ();

		c_stack ( c_stack& source ) = delete;

		c_stack ( c_stack&& other ) = delete;

		c_stack operator= ( c_stack& source ) = delete;

		c_stack operator= ( c_stack&& other ) = delete;

		~c_stack ();

		void push ( T node );

		std::optional< T > pop ();

};


template < typename T >
c_stack< T >::c_stack () : top_( nullptr ) {
}


template < typename T >
c_stack< T >::~c_stack () {
	delete this->top_;
}


template < typename T >
void c_stack< T >::push ( T node ) {
	std::lock_guard< std::mutex > lock( this->mutex_ );
	c_node< T >*                  new_node( new c_node< T >( node ) );
	new_node->set_next( this->top_ );
	this->top_ = new_node;
}


template < typename T >
std::optional< T > c_stack< T >::pop () {
	std::lock_guard< std::mutex > lock( this->mutex_ );
	if(this->top_ != nullptr) {
		T            data    = this->top_->get_data();
		c_node< T >* old_top = this->top_;
		this->top_           = old_top->get_next();
		old_top->set_next( nullptr );
		delete old_top;
		return data;
	}
	return std::nullopt;
}
