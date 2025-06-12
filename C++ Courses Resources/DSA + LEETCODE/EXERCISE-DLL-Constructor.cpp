#include <iostream>

using namespace std;


	// CREATE NODE CLASS HERE //
	//                        //
	//                        //
	//                        //
	//                        //
	////////////////////////////


class DoublyLinkedList {
    private:
		// CREATE MEMBER VARIABLES HERE //
		//                              //
		//                              //
		//                              //
		//                              //
		//////////////////////////////////

    public:
		// CREATE DLL CONSTRUCTOR HERE //
		//                             //
		//                             //
		//                             //
		//                             //
		/////////////////////////////////

        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

};



int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "\nDoubly Linked List:\n";
    myDLL->printList();

    /*
        EXPECTED OUTPUT:
        ----------------
        Head: 7
        Tail: 7
        Length: 1

        Doubly Linked List:
        7

    */
        
}

