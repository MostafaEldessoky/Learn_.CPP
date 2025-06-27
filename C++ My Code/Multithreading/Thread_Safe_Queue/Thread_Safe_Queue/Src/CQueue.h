#pragma once
#include <mutex>
#include <optional>
#include "CNode.h"


template < typename T >
class c_queue {
	std::atomic< c_node< T >* > front_;
	std::atomic< c_node< T >* > back_;
	std::mutex                  mutex1_;
	std::mutex                  mutex2_;
	std::mutex                  mutex3_;


	public:

		c_queue () : front_( nullptr ), back_( nullptr ) {
		}


		~c_queue () {
			this->front_      = nullptr;
			c_node< T >* temp = this->back_;
			this->back_       = nullptr;
			delete temp;
		}


		c_queue ( const c_queue& ) = delete;

		c_queue ( c_queue&& ) = delete;

		c_queue& operator= ( const c_queue& ) = delete;

		c_queue& operator= ( c_queue&& ) = delete;


		std::optional< T > pop ();

		void push ( T );

};


template < typename T >
std::optional< T > c_queue< T >::pop () {
	if(this->back_.load() != nullptr) {
		if(this->back_.load() == this->front_.load()) {
			mutex1_.lock();
			T            data = this->back_.load()->get_data();
			c_node< T >* temp = this->back_;
			this->front_      = nullptr;
			this->back_       = nullptr;
			delete temp;
			mutex1_.unlock();
			return data;
		}
		mutex2_.lock();
		T            data = this->back_.load()->get_data();
		c_node< T >* temp = this->back_;
		this->back_       = this->back_.load()->get_next();
		temp->set_next( nullptr );
		delete temp;
		mutex2_.unlock();
		return data;
	}
	return std::nullopt;

}


template < typename T >
void c_queue< T >::push ( T data ) {
	if(this->front_.load() == nullptr) {
		mutex1_.lock();
		c_node< T >* temp = new c_node< T >( data );
		this->back_.store( temp );
		this->front_.store( temp );
		mutex1_.unlock();
	}
	else {
		mutex3_.lock();
		c_node< T >* temp = new c_node< T >( data );
		this->front_.load()->set_next( temp );
		this->front_.store( temp );
		mutex3_.unlock();
	}
}
