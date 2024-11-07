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

    // Dynamically allocate the old 3D array in a 1D representation
    int* arr = new int[oldDepth * oldRows * oldCols];

    // Input values in column-major order
    cout << "Enter old array elements (column-major order):" << endl;
    for (int d = 0; d < oldDepth; d++) {
        for (int j = 0; j < oldCols; j++) {
            for (int i = 0; i < oldRows; i++) {
                int index = d * (oldRows * oldCols) + j * oldRows + i;
                cin >> arr[index];
            }
        }
    }

    // Display the old array in column-major order
    cout << "\nOld Array in Column-Major Order:" << endl;
    for (int d = 0; d < oldDepth; d++) {
        cout << "Layer " << d + 1 << ":\n";
        for (int i = 0; i < oldRows; i++) {
            for (int j = 0; j < oldCols; j++) {
                int index = d * (oldRows * oldCols) + j * oldRows + i;
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

    // Dynamically allocate the new 3D array in a 1D representation
    int* newArr = new int[newDepth * newRows * newCols];

    // Copy elements from old array to new array within bounds
    for (int d = 0; d < oldDepth && d < newDepth; d++) {
        for (int j = 0; j < oldCols && j < newCols; j++) {
            for (int i = 0; i < oldRows && i < newRows; i++) {
                int oldIndex = d * (oldRows * oldCols) + j * oldRows + i;
                int newIndex = d * (newRows * newCols) + j * newRows + i;
                newArr[newIndex] = arr[oldIndex];
            }
        }
    }

    // Fill remaining elements with 0 if new array is larger
    for (int d = 0; d < newDepth; d++) {
        for (int j = 0; j < newCols; j++) {
            for (int i = 0; i < newRows; i++) {
                int newIndex = d * (newRows * newCols) + j * newRows + i;
                if (d >= oldDepth || j >= oldCols || i >= oldRows) {
                    newArr[newIndex] = 0;
                }
            }
        }
    }

    // Display the updated new array in column-major order
    cout << "\nUpdated Array in Column-Major Order:" << endl;
    for (int d = 0; d < newDepth; d++) {
        cout << "Layer " << d + 1 << ":\n";
        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < newCols; j++) {
                int newIndex = d * (newRows * newCols) + j * newRows + i;
                cout << newArr[newIndex] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Free memory
    delete[] arr;
    delete[] newArr;

    return 0;
}
