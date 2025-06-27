#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>
#include "CStack.h"


std::mutex mtx;


std::optional< int > poping ( c_stack< int >* stack ) {
	auto x = stack->pop();
	if(x.has_value()) {
		mtx.lock();
		std::cout << "Popping: " << x.value() << std::endl;
		mtx.unlock();
		return x.value();
	}
	std::lock_guard< std::mutex > lock( mtx );
	std::cout << "Popping: No value" << std::endl;
	return std::nullopt;
}


void poshing ( int x , c_stack< int >* stack ) {
	stack->push( x );
	mtx.lock();
	std::cout << "Pushing: " << x << std::endl;
	mtx.unlock();
}


int main () {

	c_stack< int >* stack = new c_stack< int >();

	std::vector< int > data( 100 );
	std::iota( data.begin() , data.end() , 0 );
	std::vector< std::thread > threads;
	for(int i = 0 ; i < 100 ; i++) {
		threads.emplace_back( poshing , data[i] , std::ref( stack ) );
		if(i % 2 == 0) {
			threads.emplace_back( poping , std::ref( stack ) );
		}
	}

	for(auto& thread : threads) {
		if(thread.joinable()) {
			thread.join();
		}
	}
	delete stack;

	return 0;
}
