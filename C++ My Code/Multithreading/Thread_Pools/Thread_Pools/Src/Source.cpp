#include <atomic>
#include "ThreadPool.h"

std::atomic var = 0;


int func ( const int& count ) {
	for(int i = 0 ; i < count ; i++) {
		++var;
	}
	std::cout << "func called in thread " << std::this_thread::get_id() << "\n";
	return var;
}


int main () {

	thread_local int count = 1000000;

	thread_pool< int > pool;

	for(int i = 0 ; i < 100 ; i++) {
		pool.process( func , count );
	}
	return 0;
}
