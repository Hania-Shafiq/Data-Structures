#include <iostream>
#include <vector>
using namespace std;

void printGraph(const vector<int> adj[], int V) {
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int connections : adj[i]) {
            cout << connections << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;  // Example with 4 vertices
    vector<int> adacencyListj[4];

    // Adding edges to the adjacency list
    adacencyListj[0] = {1, 2};
    adacencyListj[1] = {0, 3};
    adacencyListj[2] = {0};
    adacencyListj[3] = {1,2,3,4};
 
    // Print the adjacency list
    printGraph(adacencyListj, V);

    return 0;
}
