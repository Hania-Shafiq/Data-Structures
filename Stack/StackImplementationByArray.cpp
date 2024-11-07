#include <iostream>
using namespace std;
#define n 100

class stack {
    int* arr;
    int top;
public:
    stack() {
        arr = new int[n];
        top = -1;
    }

    // PUSH
    void push(int val) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    // POP
    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }
    
    //TOP
    int Top() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    
    //ISEMPTY
    bool isEmpty() {
        return top == -1;
    }
    
    // DISPLAY
    void display() { 
        if (top == -1) { 
            cout << "Stack is empty" << endl; 
            return; 
        } 
        cout << "Stack elements: "; 
        for (int i = 0; i <= top; i++) { 
                cout << arr[i] << " "; 
            } 
            cout << endl;
    }
};

int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout << "Top is: " << st.Top() << endl;
    cout << "Is stack empty: " << st.isEmpty() << endl;
    st.display();
    return 0;
}
