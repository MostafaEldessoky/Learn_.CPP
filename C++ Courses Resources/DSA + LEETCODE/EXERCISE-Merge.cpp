#include <iostream>

using namespace std;


	// CREATE MERGE FUNCTION HERE //
	//                            //
	//                            //
	//                            //
	//                            //
	////////////////////////////////
 
 
int main() {
    
    int myArray[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;


    merge(myArray, leftIndex, midIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 8 
        
     */

}

