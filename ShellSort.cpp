#include <iostream>

void shellSort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
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
    }


int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    
    shellSort(arr, n);
    
    std::cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
