#pragma once
#include <shared_mutex>
#include <thread>


class flag {

	protected:

		std::shared_mutex mutex_;
		bool              stop_signal_;


	public:

		flag () : stop_signal_( false ) {
		}


		void stop () {
			std::lock_guard lock( this->mutex_ );
			this->stop_signal_ = true;
		}


		bool is_stopped () {
			std::shared_lock lock( this->mutex_ );
			return this->stop_signal_;
		}

};


class Jthread {

	std::thread thread_;


	public:

		flag stop_signal_;

		template < typename F , typename... Args >
		Jthread ( F , Args... );

		~Jthread ();

};


template < typename F , typename... Args >
inline Jthread::Jthread ( F f , Args... args ) {
	this->thread_ = std::thread( [this, f, args...] () {
		f( args... );
	} );
}


inline Jthread::~Jthread () {
	if(this->thread_.joinable()) {
		this->thread_.join();
	}
}
