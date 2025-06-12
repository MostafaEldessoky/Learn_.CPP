#include <iostream>
#include <string>
#include <memory>

class myerror : public std::exception {

public:

	myerror() = default;
	~myerror() = default;

	virtual const char* what() const noexcept override {
		return "myerror exception occurred";
	}
};


void fn2();
void fn3();
std::shared_ptr<int> p1 = std::make_shared<int>(42);

void fn1() {
	std::cout << "fn1 start" << std::endl;
	fn2();
	std::cout << "fn1 end" << std::endl;
}

void fn2() {

	std::cout << "fn2 start" << std::endl;
	fn3();
	std::cout << "fn2 end" << std::endl;
}

void fn3() {
	int* rawPtr = new int(100); // memory leak if not handled properly
	std::shared_ptr<int> p2{ p1 }; // no memory leak here, shared ownership
	std::cout << "Shared pointer count: " << p2.use_count() << std::endl;
	std::cout << "fn3 start" << std::endl;
	std::cout << "Shared pointer count: " << p1.use_count() << std::endl;
	throw myerror{}; // destroying p2 and will not delete rawPtr
	std::cout << "fn3 end" << std::endl;
	delete rawPtr; // This line will not be executed due to the exception
}


int main() {
	
	std::cout << "Shared pointer count: " << p1.use_count() << std::endl;
	std::cout << "main start" << std::endl;
	try {
		fn1();
	} catch (const myerror& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	} 
	std::cout << "main end" << std::endl;
	std::cout << "Shared pointer count: " << p1.use_count() << std::endl;

	return 0;
}