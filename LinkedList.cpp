#include <iostream>
using namespace std;

// Creating struct for node
struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    // Constructor to initialize head as null
    LinkedList() : head(NULL) {}

    // INSERTION
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        // New node inserted will point to previous head
        newNode->next = head;
        // Update new node as head
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        // If list was empty, set as first node
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPos(int value, int position) {
        if (position < 1) {
            cout << "Position should be valid (>=1)" << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;

        // Traversing to the node before the desired position
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        // If position is out of range
        if (!temp) {
            cout << "Position out of range" << endl;
            delete newNode;
            return;
        }
        // Insert at desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    //DELETION
   void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }

    // Function to Delete the last node of the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = NULL;   
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        //  Delete the last node
        delete temp->next; 
        // Set the second-to-last node's next to NULL
        temp->next = NULL; 
    }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next; 
        // Update the next pointer
        temp->next = temp->next->next;   
         // Delete the node
        delete nodeToDelete;            
    }

    
    //DISPLAY
    void display(){
        if(!head){
            cout<<"list is empty";
            return;
        }
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    
    //SEARCH
    bool search(int value){
        Node* temp=head;
        int position=1;
        while(temp){
            if(temp->data==value){
                cout<<"value"<<value<<"found at"<<position<<endl;
                return true;
            }
            temp = temp->next; // Move to the next node
            position++; // Increment position

        }
        cout<<"value"<<value<<"not found\n";
        return false;
    }


};

int main() {
    LinkedList list;

    // Insertion examples
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPos(15, 2);
    list.insertAtPos(25, 4);
    list.insertAtPos(35, 3);

    cout << "Linked List after insertions: ";
    list.display();

    // Deletion examples
    list.deleteFromBeginning();
    cout << "Linked List after deleting at beginning: ";
    list.display();

    list.deleteFromEnd();
    cout << "Linked List after deleting at end: ";
    list.display();

    list.deleteFromPosition(2);
    cout << "Linked List after deleting from position 2: ";
    list.display();

    // Search examples
    list.search(15);  // Searching for a value that exists
    list.search(40);  // Searching for a value that does not exist

    return 0;
}


