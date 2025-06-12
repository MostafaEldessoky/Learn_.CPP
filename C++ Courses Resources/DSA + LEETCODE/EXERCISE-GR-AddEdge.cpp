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

        bool addVertex(string vertex) {
            if (adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;
        }

        // WRITE ADDEDGE MEMBER FUNCTION HERE //
        //                                    //
        //                                    //
        //                                    //
        //                                    //
        //                                    //
        ////////////////////////////////////////

};



int main() {

    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");

    cout << "Graph before addEdge(): \n";
    myGraph->printGraph();


    myGraph->addEdge("A", "B");


    cout << "\n\nGraph after addEdge(): \n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph before addEdge(): 
        B: [ ]
        A: [ ]


        Graph after addEdge(): 
        B: [ A ]
        A: [ B ]

    */     
      
}

