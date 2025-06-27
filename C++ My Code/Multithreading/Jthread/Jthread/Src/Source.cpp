#include <iostream>
#include <thread>
#include "Jthread.h"


void threadFunction ( std::stop_token stop ) {
	while(!stop.stop_requested()) {
		// Do some work here
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) ); // Simulate work
		std::cout << "Working in thread..." << std::endl;
	}
	// Cleanup if needed
	std::cout << "Thread stopping..." << std::endl;
}


void JthreadFunction ( flag& stop ) {
	while(!stop.is_stopped()) {
		// Do some work here
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) ); // Simulate work
		std::cout << "Working in thread..." << std::endl;
	}
	// Cleanup if needed
	std::cout << "Thread stopping..." << std::endl;
}


void JthreadFunction2 () {
	// Do some work here
	std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) ); // Simulate work
	std::cout << "Working in thread..." << std::endl;
	// Cleanup if needed
	std::cout << "Thread stopping..." << std::endl;
}


int main () {

	Jthread jthread( JthreadFunction , std::ref( jthread.stop_signal_ ) );
	std::this_thread::sleep_for( std::chrono::seconds( 1 ) ); // Simulate main thread work
	jthread.stop_signal_.stop(); // Request the thread to stop

	Jthread jthread2( JthreadFunction2 );
	std::this_thread::sleep_for( std::chrono::seconds( 1 ) ); // Simulate main thread work
	jthread2.stop_signal_.stop(); // Request the thread to stop

	std::jthread workerThread( threadFunction );
	// The jthread automatically joins when it goes out of scope, no need to call join explicitly
	// Simulate main thread work
	std::this_thread::sleep_for( std::chrono::seconds( 1 ) ); // Simulate main thread work
	workerThread.request_stop(); // Request the thread to stop

	return 0;
}
