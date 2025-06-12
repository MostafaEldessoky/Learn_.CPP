// Linear_Convolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter your First Vector size : " << std::endl;
    int size_1;
    std::cin >> size_1;
    std::cout << "Enter your Second Vector size : " << std::endl;
    int size_2;
    std::cin >> size_2;
    std::cout << "Enter your First Vector : " << std::endl;
	int* vector_1 = new int[size_1 + size_2 - 1] {0}; // didnt free memory
    for (int i = 0; i < size_1; i++)
    {
        std::cin >> *(vector_1 + i);
	}
    std::cout << "Enter your Second Vector : " << std::endl;
    int* vector_2 = new int[size_1 + size_2 - 1] {0}; // didnt free memory
    for (int i = 0; i < size_2; i++)
    {
        std::cin >> *(vector_2 + i);
    }
    std::cout << "Vector 1 : " << "[";
    for (int i = 0; i < size_1 + size_2 - 1; i++) {
		std::cout << *(vector_1 + i) << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Vector 2 : " << "[";
    for (int i = 0; i < size_1 + size_2 - 1; i++) {
        std::cout << *(vector_2 + i) << " ";
    }
    std::cout << "]" << std::endl;
    
    for (int i = size_1 + size_2 - 2, j =0; i >= (size_1 + size_2 - 1) / 2; i--,j++) {
		int temp = *(vector_1 + j);
        *(vector_1 + j) = *(vector_1 + i);
		*(vector_1 + i) = temp;
    }
    std::cout << "Vector 1 after rotation : " << "[";
    for (int i = 0; i < size_1 + size_2 - 1; i++) {
        std::cout << *(vector_1 + i) << " ";
    }
    std::cout << "]" << std::endl;

    int* result = new int[size_1 + size_2 - 1] {0}; // didnt free memory

    std::cout << "result : " << "[";
    for (int i = 0 ; i < size_1 + size_2 - 1 ; i++) {
        for (int j = 0; j < size_1 + size_2 - 1; j++) {
			*(result + size_1 + size_2 - 2 - i) += *(vector_1 + (j + i) % (size_1 + size_2 - 1)) * *(vector_2 + j);
        }
    }
    for (int i = 0; i < size_1 + size_2 - 1; i++) {
        std::cout << *(result + i) << " ";
    }
    std::cout << "]" << std::endl;

	delete[] vector_1;
	delete[] vector_2;
    delete[] result;
	return 0;

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
