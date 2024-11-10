//BINARY SEARCH TREE
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value),left(NULL),right(NULL){}
};

//INSERTION FUNCTION
Node* insert(Node* node,int data){
    if(node==NULL){
        return new Node(data);
    }
    else if(node->data==data){
        return node;
    }
    else if(node->data>data){
        node->left=insert(node->left,data);
    }
    else if(node->data<data){
        node->right=insert(node->right,data);
    }
    return node;
}

//DELETION
Node* minValueNode(Node* node) {
    Node* current = node;
    // Loop to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return root;
    }

    // Recursively find the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }else if (root->data == key){
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


//DISPLAY
void printInorder(Node* node){
    if(node==NULL){
        return;
    }
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}
void printPreorder(Node* node){
    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printPostorder(Node* node){
    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}
void printdescendingorder(Node* node){
    if(node==NULL){
        return;
    }
    printdescendingorder(node->right);
    cout<<node->data<<" ";
    printdescendingorder(node->left);
    
}
int main(){
    Node* root=new Node(50);
    cout<<"Binary Tree after insertions: \n";
    insert(root,50);
    insert(root,20);
    insert(root,70);
    insert(root,70);
    printInorder(root);
    cout<<"\nBinary Tree after deletion: \n";
    deleteNode(root,20);
    printInorder(root);
    cout<<"\nDescending Order"<<endl;
    printdescendingorder(root);
    return 0;
}

