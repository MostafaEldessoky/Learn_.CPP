#include <iostream>
#include "MyString.h"
#include <vector>

int main() {
	MyString empty;
	MyString hello{"hello"};
	std::vector<MyString> vec;
	vec.push_back(MyString("hello3"));
	{
		MyString hello2{ hello };
	}
	empty = MyString{"www"};
	empty = "World";

	MyString str1{ "HELLO" };
	MyString str2;
	str2 = -str1;
	MyString str3 = str1 + " " + str2;
	std::cout << str3.get_str() << std::endl;
	std::cout << (str1 == str2) << std::endl;
	return 0;
}