//INSERTION SORT
#include<iostream>
using namespace std;

//INSERTION SORT
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){ //unsorted array
        int current=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>current){//sorted array
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}

int main(){
    int n;
    cout<<"INPUT ARRAY SIZE:\n";
    cin>>n;
    cout<<"INPUT ARRAY ELEMENTS;\n";
    int arr[n];
    //input array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    //output array
    cout<<"SORTED ARRAY:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


//Time complexity: O(n^2)
//Auxiliary Space Complexity: O(1)
