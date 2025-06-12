// Stars_formater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void stars_1(const int&);
void stars_2(const int&);

int main()
{
    std::cout << "Welcome To Stars Formater \n";
    
    while (true) {
        int num;
        std::cout << "Enter Your Max Number Of Stars : ";
        std::cin >> num;
        if (num <= 0) {
            std::cout << "Please Enter A Positive Number \n";
            continue;
		}
		char choice;
        std::cout << "Enter Your formater type ^/L ";
		std::cin >> choice;
        switch (choice) {
            case '^':
                stars_1(num);
                break;
            case 'L':
                stars_2(num);
                break;
            default:
                std::cout << "Invalid choice, please enter ^ or L \n";
				continue;
        }
        char end;
        std::cout << "do you want to end program y/n \n";
		std::cin >> end;
        if (end == 'y') {
            break;
        }
    }
}

void stars_1(const int& max) {
	std::string star = "";
    for (int i = 0; i <= max; i++) {
		star += " ";
    }
    if (max % 2 == 0) {
        for (int i = 0; i < max / 2; i++) {
			star[max / 2 -i] = '*';   
            star[max / 2 + 1 + i] = '*';
			std::cout << star << "\n";
        }
        for (int i{ max }; i > (max / 2) + 1; i--) {
            star[i ] = ' ';
            star[max - i + 1] = ' ';
            std::cout << star << "\n";
        }
    }
    else {
        for (int i = 0; i < (max / 2) + 1; i++) {
            star[max / 2 + 1 + i] = '*';
            star[max / 2 + 1 - i] = '*';
            std::cout << star << "\n";
        }
        for (int i{ max }; i > (max / 2) + 1; i--) {
            star[i ] = ' ';
            star[max - i + 1] = ' ';
            std::cout << star << "\n";
        }
    }
}

void stars_2(const int& max) {
	std::string star = "";
    for (int i{1}; i <= max; i++) {
		star += "*";
        std::cout << star  << "\n";
    }
    for (int i{max-1}; i >= 1; i--) {
        star[i] = ' ';
        std::cout << star << "\n";
    }
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
