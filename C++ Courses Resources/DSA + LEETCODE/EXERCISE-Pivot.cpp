#include <iostream>

using namespace std;


void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}


	// CREATE PIVOT FUNCTION HERE //
	//                            //
	//                            //
	//                            //
	//                            //
	////////////////////////////////



int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    int returnedIndex = pivot(myArray, 0, size-1);

    cout << "Returned Index: " << returnedIndex << "\n\n";

    for (auto value : myArray) {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        Returned Index: 3

        2 1 3 4 6 7 5  
        
     */
    
}

