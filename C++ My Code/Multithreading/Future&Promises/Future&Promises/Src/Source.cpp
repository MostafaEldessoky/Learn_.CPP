#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void doWork(std::promise<int>& promise, int x) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	promise.set_value(x);
}

template<typename T>
void doWork2(T& future) {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	int x = future.get();
	mtx.lock();
	std::cout << "Value received: " << x << std::endl;
	mtx.unlock();
}



int main() {

	std::promise<int> promise;
	std::shared_future<int> future1 = promise.get_future();
	auto future2 = future1;

	std::thread workerThread(doWork, std::ref(promise), 50);
	std::thread workerThread2(doWork2<std::shared_future<int>>, std::ref(future1));
	std::thread workerThread3(doWork2<std::shared_future<int>>, std::ref(future2));

	workerThread.join();
	workerThread2.join();
	workerThread3.join();

	std::promise<int> promise2;
	std::future<int> future = promise2.get_future();

	std::thread workerThread4(doWork, std::ref(promise2), 70);
	std::thread workerThread5(doWork2<std::future<int>>, std::ref(future));

	workerThread4.join();
	workerThread5.join();

	std::cout << "All threads completed successfully." << std::endl;

	return 0;
}