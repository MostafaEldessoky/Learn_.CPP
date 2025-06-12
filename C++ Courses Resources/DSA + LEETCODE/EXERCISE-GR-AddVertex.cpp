#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Graph {
    private:
        unordered_map<string, unordered_set<string> > adjList;
    
    public:
        void printGraph() {
            unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
            while (kvPair != adjList.end()) {
                cout  << kvPair->first << ": [ ";  // this prints out the vertex
                unordered_set<string>::iterator edge = kvPair->second.begin();
                while (edge != kvPair->second.end()) {
                    cout  << edge->data() << " ";  // this prints out edges
                    edge++;
                }
                cout << "]" << endl;
                kvPair++;
            }
        }

        // WRITE ADDVERTEX MEMBER FUNCTION HERE //
        //                                      //
        //                                      //
        //                                      //
        //                                      //
        //                                      //
        //////////////////////////////////////////

};



int main() {

    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    
    cout << "Graph:\n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph:
        B: [ ]
        A: [ ]

    */ 
       
}

