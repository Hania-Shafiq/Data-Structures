#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Pre-order traversal (Visit root, then left, then right)
void dfs(Node* root) {
    if (!root) return;
    cout << root->data << " ";  // Process the current node
    dfs(root->left);            // Traverse left subtree
    dfs(root->right);           // Traverse right subtree
}

int main() {
    // Manually create nodes
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    
    cout << "Pre-order traversal: ";
    dfs(root);  // Call DFS to perform pre-order traversal
    cout << endl;
    
    return 0;
}
