#pragma once
#include <string>
#include <vector>

class Vigenere
{
	std::string KeyLetter;
	std::vector<int> KeyNumber;

	void convert2num(std::vector<int>& vec, std::string s);

	std::string  convert2string(std::vector<int>& vec);

public:

	Vigenere(std::string key);
	~Vigenere() = default;

	void encrypt(std::string inputfile,std::string outputfile);
	void decrypt(std::string inputfile, std::string outputfile);

};

