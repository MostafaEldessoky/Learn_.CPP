// Listed_Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

void print_numbers(const std::vector<float>&);
void add_number(std::vector<float>&, float&);
void mean(const std::vector<float>&);
void smallest(const std::vector<float>&);
void largest(const std::vector<float>&);

int main()
{
    std::cout << "Enter Your Choice\n\n" << "P-Print Numbers\n" << "A-Add a Number\n" << "M-Display Mean of the Numbers\n" << "S-Display the Smallest Number\n" << "L-Display the Largest Number\n" << "Q-Quit\n" << std::endl;
	
	char choice;

	float n;

	std::vector<float> numbers;

	int i {0};
	do {
		std::cin >> choice;
		switch (choice) {
		case 'P':{
			print_numbers(numbers);
			break;
		}
		case 'A': {
			std::cin >> n ;
			add_number(numbers,n);
			break;
		}
		case 'M': {
			mean(numbers);
			break;
		}
		case 'S': {
			smallest(numbers);
			break;
		}
		case 'L': {
			largest(numbers);
			break;
		}
		case 'Q': {
			std::cout << "Goodbye\n" << std::endl;
			i = 1;
			break;
		}
		default: {
			std::cout << "Invalid choice, please try again.\n" << std::endl;
		}
	
}
	} while (i == 0);

}

void print_numbers(const std::vector<float>&  nums) {
	std::cout << "[ ";
	for (auto &num : nums) {
		std::cout << num << " ";
	}
	std::cout << "]\n" << std::endl;
}

void add_number(std::vector<float>& nums, float& n) {
	nums.push_back(n);
	std::cout << "Number added successfully\n" << std::endl;
}
void mean(const std::vector<float>& nums) {
	float temp {};
	for (int i = 0; i < nums.size(); i++)
	{
		temp += nums.at(i);
	}
	float mean = temp / (float) nums.size();
	std::cout << "Mean of the numbers is: " << mean << "\n" << std::endl;
}
void smallest(const std::vector<float>& nums) {
	float smallest = nums.at(0);
	for (int i = 1; i < nums.size(); i++) {
		if (nums.at(i) < smallest) {
			smallest = nums.at(i);
		}
	}
	std::cout << "Smallest number is: " << smallest << "\n" << std::endl;
}
void largest(const std::vector<float>& nums) {
	float largest = nums.at(0);
	for (int i = 1; i < nums.size(); i++) {
		if (nums.at(i) > largest) {
			largest = nums.at(i);
		}
	}
	std::cout << "Largest number is: " << largest << "\n" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
