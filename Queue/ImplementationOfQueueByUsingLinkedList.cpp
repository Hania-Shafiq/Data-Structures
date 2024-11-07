//IMPLEMENTATION OF QUEUE USING LINKEDLIST
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    Node* front;
    Node* back;
    public:
    Queue(){
        front==back==NULL;
    }
    
    //ENQUE
    void enque(int val){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=NULL:
        if(back==NULL){
            front==back==newNode;
            return;
        }
        back->next=newNode;
        back=newNode;
    }
    
    //DEQUE
    void deque(){
        Node* newNode=new Node();
        if(front==NULL){
            
        } //will continue it tommorow
    }
};
