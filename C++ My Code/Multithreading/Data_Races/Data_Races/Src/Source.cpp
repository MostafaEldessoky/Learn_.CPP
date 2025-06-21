#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// Mutexes 
std::mutex mtx;
// Timed mutexes
std::timed_mutex tmtx;
// Recursive mutexes
std::recursive_mutex rmtx;
// Recursive timed mutexes
std::recursive_timed_mutex rtmtx;
// Shared mutexes (C++17) more over heads than exclusive mutexes, but allows multiple readers and one writer
#include <shared_mutex>
std::shared_mutex smtx;

int x = 1;


void read()
{
	//std::shared_lock<std::shared_mutex> lock(smtx); // C++17	
	smtx.lock_shared();
	// std::cout << x << "\n";
	std::this_thread::sleep_for(std::chrono::microseconds(500));
	smtx.unlock_shared();
}

void write()
{
	//std::lock_guard<std::shared_mutex> lock(smtx); // C++17
	smtx.lock();
	x++;
	smtx.unlock();
}



void func(std::string s)
{
	std::lock_guard<std::mutex> lock(mtx);
	std::cout << "Thread ID " << std::this_thread::get_id() << s << " started\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int rec(int x)
{
	if (x == 1 || x == 0)
	{
		std::cout << "Thread ID " << std::this_thread::get_id() << " calculating factorial of " << x << "\n";
		return 1;
	}
	std::lock_guard<std::recursive_mutex> lock(rmtx);
	return x * rec(x - 1);
}

void func2(std::string s)
{
	std::unique_lock<std::timed_mutex> lock(tmtx, std::defer_lock);
	if (!lock.try_lock_for(std::chrono::milliseconds(500)))
	{
		std::cout << "Thread ID " << std::this_thread::get_id() << s << " could not acquire lock\n";
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "Thread ID " << std::this_thread::get_id() << s << " started\n";
		lock.unlock();
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

class singleton
{
	singleton* single;

public:

	singleton() : single(nullptr) {}
	singleton(const singleton&) = delete; // Delete copy constructor
	singleton& operator=(const singleton&) = delete; // Delete copy assignment operator
	singleton(singleton&&) = delete; // Delete move constructor
	singleton& operator=(singleton&&) = delete; // Delete move assignment operator

	static singleton& get_instance()
	{
		static singleton instance; // Instantiated on first use even in a multithreaded environment
		return instance;
	}

};

void sing()
{
	auto& i = singleton::get_instance();
	mtx.lock();
	std::cout << "Singleton instance address: " << &i << "\n";
	mtx.unlock();
}

thread_local int thread_local_var = 0; // Thread-local storage variable

void sing2()
{
	thread_local_var++;
	mtx.lock();
	std::cout << "Thread ID " << std::this_thread::get_id() << " thread_local_var: " << thread_local_var << "\n";
	mtx.unlock();
}

int main() {

	std::vector<std::thread> sing2threads;
	for (int i = 0; i < 10; ++i) {
		sing2threads.emplace_back(sing2);
	}
	for (auto& t : sing2threads) {
		if (t.joinable()) {
			t.join();
		}
	}

	std::vector<std::thread> singthreads;
	for (int i = 0; i < 10; ++i) {
		singthreads.emplace_back(sing);
	}
	for (auto& t : singthreads) {
		if (t.joinable()) {
			t.join();
		}
	}

	std::vector<std::thread> threads;
	for (int i = 0; i < 1; ++i) {
		threads.emplace_back(write);
	}
	for (int i = 0; i < 20; ++i) {
		threads.emplace_back(read);
	}
	for (auto& t : threads) {
		if (t.joinable()) {
			t.join();
		}
	}

	std::vector<std::thread> functhreads;
	for (int i = 0; i < 5; ++i) {
		functhreads.emplace_back(func, " A");
	}
	for (auto& t : functhreads) {
		if (t.joinable()) {
			t.join();
		}
	}
	std::vector<std::thread> functhreads2;
	for (int i = 0; i < 5; ++i) {
		functhreads2.emplace_back(func2, " B");
	}
	for (auto& t : functhreads2) {
		if (t.joinable()) {
			t.join();
		}
	}

	std::thread thrd(rec, 9);
	thrd.detach();
	std::cout << "Factorial of 5 is: " << rec(9) << "\n";

	return 0;
}