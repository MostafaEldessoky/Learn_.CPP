#include <iostream>
#include <thread>
#include "Spin_Lock.h"


int main () {

	spin_lock   lock;
	std::thread t1( [&lock] () {
		lock.lock();
		std::cout << "Thread 1 is in critical section\n";
		lock.unlock();
	} );
	std::thread t2( [&lock] () {
		lock.lock();
		std::cout << "Thread 2 is in critical section\n";
		lock.unlock();
	} );
	t1.join();
	t2.join();

	return 0;
}
