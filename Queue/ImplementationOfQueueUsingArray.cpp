//IMPLEMENTATION OF QUEUE USING ARRAY
#include <iostream>
using namespace std;
#define n 100

class queue{
    int *arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    
    //ENQUE
    void enque(int x){
        if(back==n-1){
            cout<<"queue overflow\n";
            return;
        }
        back++;
        arr[back]=x;
        cout<<"enqued "<<arr[back]<<endl;
        if(front==-1){
            front++;
        }
    }
    
    //DEQUE
    void deque(){
        if(front==-1 || front>back){
            cout<<"queue underflow\n";
            return;
        }
        cout<<arr[front]<<" dequed"<<endl;
        front++;
    }
    
    //FRONT
    int Front(){
        if(front==-1 || front>back){
            cout<<" empty queue\n";
            return -1;
        }
        return arr[front];
    }
    
    //BACK
    int Back(){
        if(back==-1){
            cout<<"empty queue\n";
            return -1;
        }
        return arr[back];
    }
    
    //ISEMPTY
    bool isEmpty(){
        if(front=-1 ||front>back){
            return true;
        }
        return false;
    }
    
    //DISPLAY
    void display(){
        if(front==-1 || front>back){
            cout<<"empty queue\n";
            return;
        }
        cout<<"QUEUE ELEMENTS: "<<endl;
        for(int i=front;i<=back;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    queue q;
    q.enque(1);
    q.enque(2);
    q.enque(11);
    q.enque(22);
    q.enque(3);
    q.deque();
    cout<<" queue front "<<q.Front()<<endl;
    cout<<" queue back "<<q.Back()<<endl;
    q.display();
}
