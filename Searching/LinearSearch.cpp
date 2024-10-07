#include <iostream>
using namespace std;
int LinearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            cout<<"Key found at index number: ";
            return i;
        }
    }
    cout<<"Key not found ";
    return -1;
}

int main(){
    cout<<"input the size of array: ";
    int n;
    cin>>n;
    int array[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int key;
    cout<<"Enter key you want to find: \n";
    cin>>key;
    cout<<LinearSearch(array,n,key)<<endl;
    return 0;
}
