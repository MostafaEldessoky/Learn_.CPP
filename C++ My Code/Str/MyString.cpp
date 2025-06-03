#include "MyString.h"
#include <cstring>
#include <iostream>

int MyString::count{ 0 };

MyString::MyString(const char* ptr) : ptr{nullptr} {
	if (ptr == nullptr) {
		std::cout << "defalt Constractor" << std::endl;
		this->ptr = new char[1] {'\0'};
	}
	else {
		std::cout << "Constractor" << std::endl;
		this->ptr = new char[std::strlen(ptr) + 1];
		for (int i = 0; i < std::strlen(ptr); i++) {
			*((*this).ptr + i) = *(ptr + i);
		}
		*((*this).ptr + std::strlen(ptr)) = '\0';
		std::cout << (*this).ptr << std::endl;
	}
}

MyString::MyString(const MyString& source) : ptr{nullptr} {
	std::cout << "Deep Copy Constractor" << std::endl;
	this->ptr = new char[std::strlen(source.ptr) + 1];
	for (int i = 0; i < std::strlen(source.ptr); i++) {
		*((*this).ptr + i) = *(source.ptr + i);
	}
	*((*this).ptr + std::strlen(source.ptr)) = '\0';
	std::cout << this->ptr << std::endl;
}

MyString::MyString(MyString&& source) noexcept : ptr{source.ptr} {
	std::cout << "Move Constractor" << std::endl;
	source.ptr = nullptr;
}

MyString::~MyString() {
	std::cout << "destractor : " << this << std::endl;
	delete[] ptr;
}

void MyString::display() const {
	std::cout << (*this).ptr << std::endl;
}

int MyString::get_len() const {
	return std::strlen(this->ptr);
}

const char* MyString::get_str() const {
	return this->ptr;
}

MyString& MyString::operator=(const MyString& rhs) {
	if (this == &rhs){
		return *this;
	}
	else {
		delete[] this->ptr;
		this->ptr = new char[std::strlen(rhs.ptr) + 1];
		for (int i = 0; i < std::strlen(rhs.ptr); i++) {
			*((*this).ptr + i) = *(rhs.ptr + i);
		}
		*((*this).ptr + std::strlen(rhs.ptr)) = '\0';
		return *this;
	}
}

MyString& MyString::operator=(MyString&& rhs) {
	delete[] this->ptr; 
	this->ptr = rhs.ptr;
	rhs.ptr = nullptr;
	return *this;
}

MyString MyString::operator-() const {
	char* new_ptr = new char[std::strlen(this->ptr) + 1];
	for (int i = 0; i < std::strlen(this->ptr);i++) {
		new_ptr[i] = std::tolower(this->ptr[i]);
	}
	new_ptr[std::strlen(this->ptr)] = '\0';
	MyString temp_string{ new_ptr };
	delete[] new_ptr; 
	return temp_string;
}

MyString MyString::operator+(const MyString& rhs) const {
	char* new_ptr = new char[std::strlen(this->ptr) + std::strlen(rhs.ptr) + 1];
	for (int i = 0; i < std::strlen(this->ptr) + std::strlen(rhs.ptr) + 1;i++) {
		if (i < std::strlen(this->ptr)) {
			new_ptr[i] = this->ptr[i];
		}
		else {
			new_ptr[i] = rhs.ptr[i - std::strlen(this->ptr)];
		}
	}
	new_ptr[std::strlen(this->ptr) + std::strlen(rhs.ptr)] = '\0';
	MyString temp_string{ new_ptr };
	delete[] new_ptr;
	return temp_string;
}

bool MyString::operator==(const MyString& rhs) const {
	return (std::strcmp(this->ptr, rhs.ptr) == 0);
}

