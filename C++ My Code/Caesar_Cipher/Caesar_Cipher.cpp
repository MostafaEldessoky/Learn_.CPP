// Caesar_Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string encript(std::string , int );
std::string decript(std::string , int );

const int ALPHABET_SIZE{ 26 };
const char ALPHABET[ALPHABET_SIZE] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
int main()
{
    std::string plain_text;
	std::string cipher_text;
	std::string massage;
	int key;

    std::cout << "Hello Enter Your Massage" << std::endl;
    std::cin >> plain_text;
	std::cout << "Hello Enter Your Key" << std::endl;
	std::cin >> key;
	
	cipher_text = encript(plain_text, key);

	std::cout << "enripted massage is : " << cipher_text << std::endl;

	massage = decript(cipher_text, key);

    std::cout << "deripted massage is : " << massage << std::endl;

}

std::string encript(std::string plain_text,int key) {
	for (int i{0}; i < plain_text.size(); i++) {
		for (int j{0}; j < sizeof(ALPHABET) / sizeof(ALPHABET[0]); j++) {
			if (plain_text[i] == ALPHABET[j]) {
				plain_text[i] = ALPHABET[(j + key) % ALPHABET_SIZE];
				break;
			}
		}
	}
	return plain_text;
}

std::string decript(std::string cipher_text, int key) {
	for (int i{}; i < cipher_text.size(); i++) {
		for (int j{}; j < sizeof(ALPHABET) / sizeof(ALPHABET[0]); j++) {
			if (cipher_text[i] == ALPHABET[j]) {
				cipher_text[i] = ALPHABET[(j - key + ALPHABET_SIZE) % ALPHABET_SIZE];
				break;
			}
		}
	}
	return cipher_text;
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
