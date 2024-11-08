#include <iostream>
using namespace std;

// HashTable class
class HashTable {
private:
    int* table;
    int size;
    int EMPTY = -1; // Special value to indicate an empty slot

public:
    // Constructor to initialize hash table
    HashTable(int size) {
        this->size = size;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = EMPTY; // Initialize all slots as empty
        }
    }

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % size;
    }

    // Insert an element into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        int startIdx = index; // Remember the start index to detect loops
        while (table[index] != EMPTY) {
            // If the table is full, we should avoid an infinite loop
            index = (index + 1) % size;
            if (index == startIdx) {
                cout << "HashTable is full. Cannot insert key " << key << endl;
                return;
            }
        }
        table[index] = key;
    }

    // Search for an element in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        int startIdx = index; // Remember the start index to detect loops
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
            if (index == startIdx) {
                break;
            }
        }
        return false;
    }

    // Delete an element from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        int startIdx = index; // Remember the start index to detect loops
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = EMPTY;
                return;
            }
            index = (index + 1) % size;
            if (index == startIdx) {
                cout << "Key " << key << " not found in the hash table." << endl;
                return;
            }
        }
        cout << "Key " << key << " not found in the hash table." << endl;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != EMPTY) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else {
                cout << "Index " << i << ": " << "EMPTY" << endl;
            }
        }
    }

    // Destructor to free memory
    ~HashTable() {
        delete[] table;
    }
};

int main() {
    int hashTableSize = 7;  // Define the size of the hash table
    HashTable ht(hashTableSize);

    // Insert elements into the hash table
    ht.insert(15);
    ht.insert(11);
    ht.insert(27);
    ht.insert(8);
    ht.insert(12);
    ht.insert(33);
    ht.insert(19);

    cout << "Hash Table after insertion:" << endl;
    ht.display();

    // Remove an element
    ht.remove(12);
    cout << "\nHash Table after deletion of 12:" << endl;
    ht.display();

    return 0;
}
