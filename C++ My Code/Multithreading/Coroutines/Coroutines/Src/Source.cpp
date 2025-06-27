#include <coroutine>
#include <iostream>
#include <optional>
#include <thread>


inline int generate () {
	static int value = 0;
	return ++value;
}


inline void print () {
	static int value = 0;
	switch(value) {
		case 0 :
			std::cout << "a";
			value++;
			break;
		case 1 :
			std::cout << "b";
			value++;
			break;
		case 2 :
			std::cout << "c";
			value++;
			break;
		case 3 :
			std::cout << "d";
			value++;
			break;
		default :
			value = 0;
			break;
	}
}


// A simple Awaitable type to simulate asynchronous behavior
struct AsyncTask {
	struct promise_type {
		AsyncTask get_return_object () {
			return AsyncTask{ std::coroutine_handle< promise_type >::from_promise( *this ) };
		}


		std::suspend_always initial_suspend () {
			return { };
		}


		std::suspend_always final_suspend () noexcept {
			return { };
		}


		void return_void () {
		}


		void unhandled_exception () {
			std::terminate();
		}
	};


	std::coroutine_handle< promise_type > handle;


	explicit AsyncTask ( std::coroutine_handle< promise_type > h ) : handle( h ) {
	}


	~AsyncTask () {
		if(handle)
			handle.destroy();
	}


	void resume () {
		if(handle && !handle.done()) {
			handle.resume();
		}
	}
};


// Simulates an asynchronous operation
struct Awaitable {
	bool await_ready () const noexcept {
		return false; // Always suspend the coroutine
	}


	void await_suspend ( std::coroutine_handle< > handle ) const {
		// Simulate a delay using a separate thread
		std::thread( [handle] () {
			std::this_thread::sleep_for( std::chrono::seconds( 2 ) ); // Simulate 2-second delay
			handle.resume(); // Resume the coroutine after the delay
		} ).detach();
	}


	void await_resume () const noexcept {
		// No result to return
	}
};


// Coroutine function to simulate an asynchronous task
AsyncTask asyncOperation () {
	std::cout << "Starting async operation...\n";
	co_await Awaitable{ }; // Suspend here and simulate an async delay
	std::cout << "Async operation completed!\n";
}


class Generator {
	public:

		struct promise_type {
			int current_value;


			// Returns the generator object to the caller
			Generator get_return_object () {
				return Generator{ std::coroutine_handle< promise_type >::from_promise( *this ) };
			}


			std::suspend_always initial_suspend () {
				return { };
			}


			std::suspend_always final_suspend () noexcept {
				return { };
			}


			// Yield a value to the caller
			std::suspend_always yield_value ( int value ) {
				current_value = value;
				return { };
			}


			void return_void () {
			}


			void unhandled_exception () {
				std::terminate();
			}
		};


		explicit Generator ( std::coroutine_handle< promise_type > h ) : handle( h ) {
		}


		~Generator () {
			if(handle)
				handle.destroy();
		}


		// Retrieve the next value from the coroutine
		std::optional< int > next () {
			if(!handle || handle.done())
				return std::nullopt;
			handle.resume();
			return handle.promise().current_value;
		}


	private:

		std::coroutine_handle< promise_type > handle;
};


// Coroutine function to generate numbers lazily
Generator numberGenerator ( int start , int end ) {
	for(int i = start ; i <= end ; ++i) {
		co_yield i; // Yield the current number
	}
}


int main () {
	auto task = asyncOperation(); // Start the coroutine
	std::cout << "Coroutine started, waiting for completion...\n";
	// Simulate doing other work while the coroutine is suspended
	std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
	std::cout << "Main thread is still working...\n";
	// Wait for the coroutine to complete
	task.resume();
	std::this_thread::sleep_for( std::chrono::seconds( 3 ) ); // Ensure the program doesn't exit prematurely

	auto gen = numberGenerator( 1 , 5 ); // Create a generator for numbers 1 to 5
	while(auto value = gen.next()) {
		std::cout << *value << " "; // Print each value
	}

	for(int i = 0 ; i < 5 ; ++i) {
		int value = generate();
		std::cout << value << " ";
	}
	for(int i = 0 ; i < 5 ; i++) {
		print();
	}
	return 0;
}
