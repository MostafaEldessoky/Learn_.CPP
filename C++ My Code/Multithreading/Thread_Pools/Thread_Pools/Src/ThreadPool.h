#pragma once
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <vector>


template < typename T >
class thread_pool {
	public:

		thread_pool ();

		~thread_pool ();

		thread_pool ( const thread_pool& ) = delete;

		thread_pool ( thread_pool&& ) = delete;

		thread_pool& operator= ( const thread_pool& ) = delete;

		thread_pool& operator= ( thread_pool&& ) = delete;


		template < typename F , typename... Args >
		void process ( F , Args... );


	private:

		std::mutex                     mux;
		std::vector< std::thread >     threads;
		std::queue< std::future< T > > queue;

};


template < typename T >
thread_pool< T >::thread_pool () {
	this->threads.resize( std::thread::hardware_concurrency() - 2 );
	for(auto& i : this->threads) {
		i = std::thread( [this] () {
			while(true) {
				std::this_thread::sleep_for( std::chrono::microseconds( 15 ) );
				bool             p = false;
				std::future< T > fn;
				this->mux.lock();
				if(!this->queue.empty()) {
					fn = std::move( this->queue.front() );
					this->queue.pop();
					p = true;
				}
				this->mux.unlock();
				std::this_thread::sleep_for( std::chrono::microseconds( 30 ) );
				if(p) {
					auto output = fn.get();
					std::cout << "output of this operation is " << output << " from thread ID " <<
						std::this_thread::get_id() << "\n";
				}
				else {
					std::this_thread::sleep_for( std::chrono::microseconds( 35 ) );
					std::cout << "output of this operation is None case of queue is empty from thread ID " <<
						std::this_thread::get_id() << "\n";
				}
			}
		} );
	}
}


template < typename T >
thread_pool< T >::~thread_pool () {
	for(auto& i : this->threads) {
		if(i.joinable()) {
			i.join();
		}
	}
	std::cout << "Thread pool destroyed." << std::endl;
}


template < typename T >
template < typename F , typename... Args >
void thread_pool< T >::process ( F f , Args... a ) {
	auto fn = std::async( std::launch::deferred , f , a... );
	this->mux.lock();
	this->queue.push( std::move( fn ) );
	this->mux.unlock();
}
