#include <chrono>
#include <future>
#include <iostream>
#include <thread>

std::string doWork(std::string s) {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << s << std::endl;
	s = "Goodbye World";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return s; // This return value will be used by the future
}


int main() {

	std::packaged_task<std::string(std::string)> task(doWork);
	auto fu = task.get_future();

	std::thread t(std::move(task), "Hello World");
	t.detach();
	std::cout << fu.get() << std::endl;
	return 0;
}