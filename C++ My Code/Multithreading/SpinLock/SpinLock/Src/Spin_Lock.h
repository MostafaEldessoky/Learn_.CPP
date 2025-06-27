#pragma once
#include <atomic>


class spin_lock {

	std::atomic_flag flag = ATOMIC_FLAG_INIT;


	public:

		void lock ();

		void unlock ();
};


inline void spin_lock::lock () {
	while(flag.test_and_set( std::memory_order_acquire )) {
	}
}


inline void spin_lock::unlock () {
	flag.clear( std::memory_order_release );
}
