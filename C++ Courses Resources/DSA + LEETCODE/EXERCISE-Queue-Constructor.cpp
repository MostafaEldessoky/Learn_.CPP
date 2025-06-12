#include <iostream>

using namespace std;


	// CREATE NODE CLASS HERE //
	//                        //
	//                        //
	//                        //
	//                        //
	////////////////////////////


class Queue {
    private:
		// CREATE MEMBER VARIABLES HERE //
		//                              //
		//                              //
		//                              //
		//                              //
		//////////////////////////////////

    public:
		// CREATE QUEUE CONSTRUCTOR HERE //
		//                               //
		//                               //
		//                               //
		//                               //
		///////////////////////////////////

        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        void printQueue() {
            Node* temp = first;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getFirst() {
            if (first == nullptr) {
                cout << "First: nullptr" << endl;
            } else {
                cout << "First: " << first->value << endl;
            }
        }

        void getLast() {
            if (last == nullptr) {
                cout << "Last: nullptr" << endl;
            } else { 
                cout << "Last: " << last->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }
        
        bool isEmpty() {
            if (length == 0) return true;
            return false;
        }

};



int main() {
        
    Queue* myQueue = new Queue(7);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    cout << "\nQueue:\n";
    myQueue->printQueue();

    /*  
        EXPECTED OUTPUT:
        ----------------
        First: 7
        Last: 7
        Length: 1

        Queue:
        7

    */    

}

