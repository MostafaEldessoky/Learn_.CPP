#include <iostream>

using namespace std;


	// CREATE BUBBLESORT FUNCTION HERE //
	//                                 //
	//                                 //
	//                                 //
	//                                 //
	/////////////////////////////////////



int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}

