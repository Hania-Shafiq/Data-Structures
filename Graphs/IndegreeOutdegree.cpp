#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    cout << "Enter the number of nodes (N): ";
    cin >> N;

    vector<vector<int>> G(N, vector<int>(N));

    // Input adjacency matrix
    cout << "Enter the adjacency matrix (weights for edges, 0 if no edge):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    // Arrays to store in-degrees and out-degrees
    vector<int> inDegree(N, 0);
    vector<int> outDegree(N, 0);

    // Calculate in-degrees by iterating over columns
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (G[i][j] != 0) {  // Check if there's an edge from node i to node j
                inDegree[j]++;
            }
        }
    }

    // Calculate out-degrees by iterating over rows
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G[i][j] != 0) {  // Check if there's an edge from node i to node j
                outDegree[i]++;
            }
        }
    }

    // Output in-degrees and out-degrees for each node
    cout << "In-Degree and Out-Degree of each node:\n";
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": In-Degree = " << inDegree[i] 
             << ", Out-Degree = " << outDegree[i] << endl;
    }

    return 0;
}
