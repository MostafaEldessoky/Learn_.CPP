#include "Vigenere.h"
#include <iostream>
#include <string>

int main() {

	std::string key;

	std::cout << "Enter the key for Vigenere cipher: ";
	std::getline(std::cin, key);

	Vigenere vigenere{key};

	vigenere.encrypt("PlainText.txt","CipherText.txt");
	vigenere.decrypt("CipherText.txt", "DecryptedText.txt");

	return 0;
}