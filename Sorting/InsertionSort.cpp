//INSERTION SORT
#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){ //unsorted part
        int current=arr[i];
        int j=i-1; //sorted part
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    int array[n];
    cout<<"Enter the elements of the array:\n";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    insertionSort(array,n);
            cout<<"Sorted array:\n";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

//Time complexity: O(n^2)
//Auxiliary Space Complexity: O(1)
