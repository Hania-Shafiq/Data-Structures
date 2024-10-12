#include<iostream>
using namespace std;
//Function to swap
void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
//Partition Function
int partition(int arr[],int low, int high){
    int pivot=arr[low];
    int p=low+1;
    int q=high;
    while(true){
        //p will increment till q and q will increment till p
       // p stops at an element > pivot. (must find greater element)
      //q stops at an element ≤ pivot. (find element lesser or equal)

        while(p<=high && !(arr[p]>pivot)){
            p++;
        }
        //decrement q till we find element less than pivot element 
        //so if arr[q] is greater than pivot decrement q
        while(q>low && !(arr[q]<=pivot)){
            q--;
        }
        if(p>=q){
            break;
        }
        //if p and q dont cross swap p element with q element
        swap(arr[p],arr[q]);
    }
    //if p and q crosses or have same position swap pivot element with q
    swap(arr[low],arr[q]);
    //its pivot index as pivot element will be swapped to q pos
    return q;
}
//QuickSort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);  // Left side of pivot
        quickSort(arr, pivotIndex + 1, high);  // Right side of pivot
    }
}
int main(){
    int array[]={22,3,6,1,8,7,22,2};
    int n=sizeof(array)/sizeof(array[0]);
    quickSort(array,0,n-1);
    //printing sorted array
    cout<<"sorted array:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

//time complexity: O(n^2)
//space complexity: O(n)
