#include <iostream>

template<typename t, int n>
class Array
{
	int size{ n };
	t array[n];

public:

	friend std::ostream& operator<< (std::ostream& os, Array& arr) {
		os << "[ ";
		for (auto& a : arr.array) {
			os << a << " ";
		}
		os << "]";
		return os;
	}

	Array() {
	
	}

	Array& fill(t v) {
		for (t& a : this->array) {
			a = v;
		}
		return *this;
	}

	t& operator[] (int i) {
		return this->array[i];
	}

};

template<typename t>
t* func(t temp) {
	t* ptr = new int {temp};
	std::cout << ptr << std::endl;
	return ptr;
}

int main() {

	Array<int,5> arr;
	std::cout << arr.fill(1) << std::endl;
	arr[1] = 2;
	std::cout << arr << std::endl;
	std::cout << arr[3] << std::endl;
	int* num = func<int>(5);
	std::cout << num << " " << *num << std::endl;
	return 0;
}