#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>

std::mutex mux;

class Thread_Garud {
	std::thread thread;

public:

	template<typename T, typename... Args>
	Thread_Garud(T func, Args... args) : thread(func, args...) {}
	~Thread_Garud() {
		if (this->thread.joinable()) {
			this->thread.join();
		}
	}

	Thread_Garud(const Thread_Garud&) = delete;
	Thread_Garud& operator=(const Thread_Garud&) = delete;
	Thread_Garud(Thread_Garud&& other) noexcept : thread(std::move(other.thread)) {}
};


void func(std::string s) {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	mux.lock();
	std::cout << "Thread started with message: " << s << std::endl;
	std::cout << "Thread started with message: " << std::this_thread::get_id() << std::endl;
	mux.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

std::thread fn(std::thread&& thrd) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	mux.lock();
	std::cout << "Thread started with message: " << thrd.get_id() << std::endl;
	mux.unlock();
	return thrd;
}



int main() {
	int x = 0;
	int y = x + 1;
	mux.lock();
	std::cout << std::this_thread::get_id() << std::endl;
	mux.unlock();
	std::thread thrd(func, "Hello from thread!");
	mux.lock();
	std::cout << thrd.get_id() << std::endl;
	mux.unlock();

	fn(std::move(thrd)).join();

	Thread_Garud thrd_garud(func, "Hello from Thread_Garud!");


	return 0;
}