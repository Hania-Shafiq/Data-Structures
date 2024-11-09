//PRINTING ADJACENCY MATRIX 

#include <iostream>
using namespace std;
#include <vector>

void printGraph(const vector<vector<int>>& graph, int V) {
    for (int i = 0; i < V; i++) {
        cout << i << "-> ";
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter no of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    
    cout << "Enter Adjacency Matrix Elements: " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int n;
            cin >> n;
            graph[i][j] =n;
        }
        cout << endl;
    }
    
    printGraph(graph, V);
    return 0;
}
