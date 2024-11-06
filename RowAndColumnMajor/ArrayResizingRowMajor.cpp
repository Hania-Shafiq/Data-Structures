#include <iostream>
using namespace std;

int main() {
    int oldRows, oldCols, newRows, newCols;

    // Input old array dimensions
    cout << "Enter old number of rows: ";
    cin >> oldRows;
    cout << "Enter old number of columns: ";
    cin >> oldCols;

    // Dynamically allocate old array
    int* arr = new int[oldRows * oldCols];

    // Set values in the old array in row-major order
    cout << "Enter old array elements (row-major order):" << endl;
    for (int i = 0; i < oldRows; i++) {
        for (int j = 0; j < oldCols; j++) {
            int index = i * oldCols + j;  // Row-major order
            cin >> arr[index];
        }
    }

    // Display the old array in row-major order
    cout << "\nOld Array in Row-Major Order:" << endl;
    for (int i = 0; i < oldRows; i++) {
        for (int j = 0; j < oldCols; j++) {
            int index = i * oldCols + j;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    // Input new array dimensions
    cout << "\nEnter new number of rows: ";
    cin >> newRows;
    cout << "Enter new number of columns: ";
    cin >> newCols;

    // Dynamically allocate memory for the new array
    int* newArr = new int[newRows * newCols];

    // Copy elements from old array to new array
    for (int i = 0; i < oldRows; i++) {
        for (int j = 0; j < oldCols; j++) {
            // Ensure we stay within the new array's boundaries
            if (i < newRows && j < newCols) {
                newArr[i * newCols + j] = arr[i * oldCols + j];
            }
        }
    }

    // Fill remaining elements with 0 in case new array is larger
    for (int i = oldRows; i < newRows; i++) {
        for (int j = oldCols; j < newCols; j++) {
            newArr[i * newCols + j] = 0;
        }
    }

    // Display the updated new array in row-major order
    cout << "\nUpdated Array in Row-Major Order:" << endl;
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            cout << newArr[i * newCols + j] << " ";
        }
        cout << endl;
    }

    // Free the memory
    delete[] arr;
    delete[] newArr;

    return 0;
}
