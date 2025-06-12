#include <iostream>
#include <vector>
#include <memory>
#include <string>

class MyClass {

public:
	~MyClass() {
		std::cout << "MyClass destructor" << std::endl;
	}

};


int main() {
	
	std::unique_ptr<int> ptr1 = std::make_unique<int>(200);
	std::cout << ptr1.get() << std::endl;
	std::cout << *ptr1 << std::endl;
	std::vector<std::unique_ptr<int>> vec1;
	vec1.push_back(std::move(ptr1)); 
	std::cout << vec1[0].get() << std::endl;
	std::cout << *vec1[0] << std::endl;

	std::shared_ptr<std::string> ptr2 = std::make_shared<std::string>("hello world!");
	std::cout << ptr2.get() << std::endl;
	std::cout << *ptr2 << std::endl;
	std::cout << ptr2.use_count() << std::endl;
	std::vector<std::shared_ptr<std::string>> vec2;
	vec2.push_back(ptr2);
	std::cout << vec2[0].get() << std::endl;
	std::cout << *vec2[0] << std::endl;
	std::cout << ptr2.use_count() << std::endl;
	std::cout << vec2[0].use_count() << std::endl;

	std::shared_ptr<MyClass> ptr3 = std::make_shared< MyClass>();
	std::cout << ptr3.get() << std::endl;
	std::weak_ptr<MyClass> weakPtr = ptr3;
	ptr3.reset(); 
	std::cout << weakPtr.use_count() << std::endl;
	std::cout << weakPtr.lock() << std::endl;
	std::cout << ptr3.use_count() << std::endl;


}