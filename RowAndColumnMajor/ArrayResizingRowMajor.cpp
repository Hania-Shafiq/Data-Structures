#include <iostream>
using namespace std;

int main() {
    int oldDepth, oldRows, oldCols, newDepth, newRows, newCols;

    // Input old array dimensions
    cout << "Enter old depth: ";
    cin >> oldDepth;
    cout << "Enter old number of rows: ";
    cin >> oldRows;
    cout << "Enter old number of columns: ";
    cin >> oldCols;

    // Dynamically allocate old 3D array
    int* arr = new int[oldDepth * oldRows * oldCols];

    // Set values in the old array in row-major order
    cout << "Enter old array elements (row-major order):" << endl;
    for (int i = 0; i < oldDepth; i++) {         // Depth outermost
        for (int j = 0; j < oldRows; j++) {      // Rows middle
            for (int k = 0; k < oldCols; k++) {  // Columns innermost
                int index = i * (oldRows * oldCols) + j * oldCols + k;
                cin >> arr[index];
            }
        }
    }

    // Display the old array in row-major order
    cout << "\nOld Array in Row-Major Order:" << endl;
    for (int i = 0; i < oldDepth; i++) {
        for (int j = 0; j < oldRows; j++) {
            for (int k = 0; k < oldCols; k++) {
                int index = i * (oldRows * oldCols) + j * oldCols + k;
                cout << arr[index] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Input new array dimensions
    cout << "\nEnter new depth: ";
    cin >> newDepth;
    cout << "Enter new number of rows: ";
    cin >> newRows;
    cout << "Enter new number of columns: ";
    cin >> newCols;

    // Dynamically allocate memory for the new array
    int* newArr = new int[newDepth * newRows * newCols];

    // Copy elements from old array to new array in row-major order
    for (int i = 0; i < oldDepth && i < newDepth; i++) {      // Depth
        for (int j = 0; j < oldRows && j < newRows; j++) {    // Rows
            for (int k = 0; k < oldCols && k < newCols; k++) {// Columns
                int oldIndex = i * (oldRows * oldCols) + j * oldCols + k;
                int newIndex = i * (newRows * newCols) + j * newCols + k;
                newArr[newIndex] = arr[oldIndex];
            }
        }
    }

    // Fill remaining elements with 0 in case new array is larger
    for (int i = 0; i < newDepth; i++) {
        for (int j = 0; j < newRows; j++) {
            for (int k = 0; k < newCols; k++) {
                int index = i * (newRows * newCols) + j * newCols + k;
                if (i >= oldDepth || j >= oldRows || k >= oldCols) {
                    newArr[index] = 0;  // Fill extra elements with 0
                }
            }
        }
    }

    // Display the updated new array in row-major order
    cout << "\nUpdated Array in Row-Major Order:" << endl;
    for (int i = 0; i < newDepth; i++) {
        for (int j = 0; j < newRows; j++) {
            for (int k = 0; k < newCols; k++) {
                int index = i * (newRows * newCols) + j * newCols + k;
                cout << newArr[index] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Free the memory
    delete[] arr;
    delete[] newArr;

    return 0;
}
