#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx1, mtx2;
void thread1() {
	std::lock(mtx1, mtx2); // Using std::lock to avoid deadlock
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "Thread 1 acquired locks\n";
	mtx1.unlock();
	mtx2.unlock();
}

void thread2() {
	std::lock(mtx1, mtx2); // Using std::lock to avoid deadlock
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "Thread 2 acquired locks\n";
	mtx1.unlock();
	mtx2.unlock();
}

int main() {

	std::thread t1(thread1);
	std::thread t2(thread2);
	t1.join();
	t2.join();

	return 0;
}