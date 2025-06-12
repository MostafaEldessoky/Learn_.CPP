#include "Vigenere.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

enum class  AlphabetLetters : int { A = 0, B, C, D, E, F, G, H, I, J, K, L,
	M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };

void Vigenere::convert2num(std::vector<int>& vec,std::string s) {
	
	vec.clear();

	for (const char& temp : s) {

		switch (temp) {
		case 'A':
		case 'a':
			vec.push_back((int)AlphabetLetters::A);
			break;
		case 'B':
		case 'b':
			vec.push_back((int)AlphabetLetters::B);
			break;
		case 'C':
		case 'c':
			vec.push_back((int)AlphabetLetters::C);
			break;
		case 'D':
		case 'd':
			vec.push_back((int)AlphabetLetters::D);
			break;
		case 'E':
		case 'e':
			vec.push_back((int)AlphabetLetters::E);
			break;
		case 'F':
		case 'f':
			vec.push_back((int)AlphabetLetters::F);
			break;
		case 'G':
		case 'g':
			vec.push_back((int)AlphabetLetters::G);
			break;
		case 'H':
		case 'h':
			vec.push_back((int)AlphabetLetters::H);
			break;
		case 'I':
		case 'i':
			vec.push_back((int)AlphabetLetters::I);
			break;
		case 'J':
		case 'j':
			vec.push_back((int)AlphabetLetters::J);
			break;
		case 'K':
		case 'k':
			vec.push_back((int)AlphabetLetters::K);
			break;
		case 'L':
		case 'l':
			vec.push_back((int)AlphabetLetters::L);
			break;
		case 'M':
		case 'm':
			vec.push_back((int)AlphabetLetters::M);
			break;
		case 'N':
		case 'n':
			vec.push_back((int)AlphabetLetters::N);
			break;
		case 'O':
		case 'o':
			vec.push_back((int)AlphabetLetters::O);
			break;
		case 'P':
		case 'p':
			vec.push_back((int)AlphabetLetters::P);
			break;
		case 'Q':
		case 'q':
			vec.push_back((int)AlphabetLetters::Q);
			break;
		case 'R':
		case 'r':
			vec.push_back((int)AlphabetLetters::R);
			break;
		case 'S':
		case 's':
			vec.push_back((int)AlphabetLetters::S);
			break;
		case 'T':
		case 't':
			vec.push_back((int)AlphabetLetters::T);
			break;
		case 'U':
		case 'u':
			vec.push_back((int)AlphabetLetters::U);
			break;
		case 'V':
		case 'v':
			vec.push_back((int)AlphabetLetters::V);
			break;
		case 'W':
		case 'w':
			vec.push_back((int)AlphabetLetters::W);
			break;
		case 'X':
		case 'x':
			vec.push_back((int)AlphabetLetters::X);
			break;
		case 'Y':
		case 'y':
			vec.push_back((int)AlphabetLetters::Y);
			break;
		case 'Z':
		case 'z':
			vec.push_back((int)AlphabetLetters::Z);
			break;
		default:
			break;
		}
	}
	
}

std::string Vigenere::convert2string(std::vector<int>& vec) {

	std::string result { "" };

	for (const int& temp : vec) {

		AlphabetLetters letter = AlphabetLetters(temp);

		switch (letter) {
		case AlphabetLetters::A:
			result += 'A';
			break;
		case AlphabetLetters::B:
			result += 'B';
			break;
		case AlphabetLetters::C:
			result += 'C';
			break;
		case AlphabetLetters::D:
			result += 'D';
			break;
		case AlphabetLetters::E:
			result += 'E';
			break;
		case AlphabetLetters::F:
			result += 'F';
			break;
		case AlphabetLetters::G:
			result += 'G';
			break;
		case AlphabetLetters::H:
			result += 'H';
			break;
		case AlphabetLetters::I:
			result += 'I';
			break;
		case AlphabetLetters::J:
			result += 'J';
			break;
		case AlphabetLetters::K:
			result += 'K';
			break;
		case AlphabetLetters::L:
			result += 'L';
			break;
		case AlphabetLetters::M:
			result += 'M';
			break;
		case AlphabetLetters::N:
			result += 'N';
			break;
		case AlphabetLetters::O:
			result += 'O';
			break;
		case AlphabetLetters::P:
			result += 'P';
			break;
		case AlphabetLetters::Q:
			result += 'Q';
			break;
		case AlphabetLetters::R:
			result += 'R';
			break;
		case AlphabetLetters::S:
			result += 'S';
			break;
		case AlphabetLetters::T:
			result += 'T';
			break;
		case AlphabetLetters::U:
			result += 'U';
			break;
		case AlphabetLetters::V:
			result += 'V';
			break;
		case AlphabetLetters::W:
			result += 'W';
			break;
		case AlphabetLetters::X:
			result += 'X';
			break;
		case AlphabetLetters::Y:
			result += 'Y';
			break;
		case AlphabetLetters::Z:
			result += 'Z';
			break;
		default:
			break;
		}
	}
	return result;
}

Vigenere::Vigenere(std::string key) : KeyLetter{ key } {
	convert2num(this->KeyNumber,this->KeyLetter);
}

void Vigenere::encrypt(std::string inputfile, std::string outputfile) {
	std::ifstream input{ inputfile };
	if (!input) {
		std::cerr << "Error opening input file: " << inputfile << std::endl;
		return;
	}
	std::ofstream output{ outputfile };
	if (!output) {
		std::cerr << "Error opening output file: " << outputfile << std::endl;
		return;
	}
	std::vector<int> vec;
	std::string line;
	while (std::getline(input, line)) {
		convert2num(vec, line);
		for (int i = 0,j = 0; i < vec.size();i++,j++) {
			if (j < this->KeyNumber.size()) {
				vec[i] = ( vec[i] + this->KeyNumber[j] + ((int)AlphabetLetters::Z + 1)) % ((int) AlphabetLetters::Z + 1);
			}
			else {
				j = 0;
				i--;
			}
		}
		output << convert2string(vec) << std::endl;
	}
	input.close();
	output.close();
}


void  Vigenere::decrypt(std::string inputfile, std::string outputfile) {
	std::ifstream input{ inputfile };
	if (!input) {
		std::cerr << "Error opening input file: " << inputfile << std::endl;
		return;
	}
	std::ofstream output{ outputfile };
	if (!output) {
		std::cerr << "Error opening output file: " << outputfile << std::endl;
		return;
	}
	std::vector<int> vec;
	std::string line;
	while (std::getline(input, line)) {
		convert2num(vec, line);
		for (int i = 0, j = 0; i < vec.size(); i++, j++) {
			if (j < this->KeyNumber.size()) {
				vec[i] = (vec[i] - this->KeyNumber[j] + ((int)AlphabetLetters::Z + 1)) % ((int)AlphabetLetters::Z + 1);
			}
			else {
				j = 0;
				i--;
			}
		}
		output << convert2string(vec) << std::endl;
	}
	input.close();
	output.close();
}
