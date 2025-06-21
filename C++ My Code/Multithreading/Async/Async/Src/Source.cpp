#include <future>
#include <iostream>


std::string func(std::string s)
{
	std::cout << "func called with: " << s << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	return "goodbye";
}




int main() {

	auto ft1 = std::async(std::launch::async, func, "Hello World");
	auto ft2 = std::async(std::launch::deferred, func, "Hello World");
	auto ft3 = std::async(func, "Hello World");

	std::cout << ft3.get() << std::endl;
	std::cout << ft1.get() << std::endl;
	std::cout << ft2.get() << std::endl;
	return 0;
}