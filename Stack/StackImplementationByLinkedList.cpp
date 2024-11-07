//IMPLEMENTATION OF STACK USING LINKED-LIST
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class stack{
    Node* top;
    public:
    stack():top(NULL){}
    
    //PUSH
    void push(int val){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=top;
        top=newNode;
        cout<<val<<" pushed at stack"<<endl;
    }
    
    //POP
    void pop(){
        Node* node=new Node();
        Node* temp=top;
        top=top->next;
        cout<<temp->data<<" popped from stack\n";
        delete temp;
    }
    
    //PEEK
    int Top(){
        if(!top){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
    
    //IS-EMPTY
    bool isEmpty(){
        return top==NULL;
    }
    
  //DISPLAY
  void display(){
      if(!top){
          cout<<"stack is empty"<<endl;
          return;
      }
      Node* temp=top;
      while(temp){
          cout<<temp->data<<"->";
          temp=temp->next;
      }
      cout<<"NULL"<<endl;
  }
  
  //DESTRUCTOR
  ~stack(){
      while(!isEmpty()){
          pop();
      }
  }
};

int main(){
    stack st;
    st.push(9);
    st.push(1);
    st.push(2);
    st.push(7);
    st.push(5);
    st.pop();
    cout<<"at top: "<<st.Top()<<endl;
    st.display();
}
