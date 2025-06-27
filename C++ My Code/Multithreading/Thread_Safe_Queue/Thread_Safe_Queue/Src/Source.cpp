#include <iostream>
#include <mutex>
#include <numeric>
#include <optional>
#include <thread>
#include <vector>
#include "CQueue.h"


std::mutex mtx;


std::optional< int > poping ( c_queue< int >* queue ) {
	auto x = queue->pop();
	if(x.has_value()) {
		mtx.lock();
		std::cout << "_Popping: " << x.value() << std::endl;
		mtx.unlock();
		return x.value();
	}
	std::lock_guard< std::mutex > lock( mtx );
	std::cout << "_Popping: No value" << std::endl;
	return std::nullopt;
}


void poshing ( int x , c_queue< int >* queue ) {
	queue->push( x );
	mtx.lock();
	std::cout << "Pushing_: " << x << std::endl;
	mtx.unlock();
}


int main () {

	c_queue< int >* queue = new c_queue< int >();

	std::vector< int > data( 100 );
	std::iota( data.begin() , data.end() , 0 );
	std::vector< std::thread > threads;
	for(int i = 0 ; i < 100 ; i++) {
		threads.emplace_back( poshing , data[i] , std::ref( queue ) );
		if(i % 2 == 0) {
			threads.emplace_back( poping , std::ref( queue ) );
		}
	}

	for(auto& thread : threads) {
		if(thread.joinable()) {
			thread.join();
		}
	}
	delete queue;

	return 0;
}
