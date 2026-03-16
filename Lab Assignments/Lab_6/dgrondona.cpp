#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:

    int tableSize;
    std::vector<list<int>> table;

    int hashFunction(int key);

public:

    // Constructor.
    HashTable(int size) {
        tableSize = size;
        table.resize(size);
    }

    // Insert key into table; i2 implies "Insert key 2 into the table".
    void insert(int key) {
        int i = hashFunction(key);
        table[i].push_back(key);
    }

    // Search table for key.
    bool search(int key) {
        int i = hashFunction(key);

        for (int j = 0; j < table[i]; j++) {
            if (j == key) {
                return true;
            }
        }

        return false;
    }

    // Delete key from the table; d2 implies “Delete key 2 from the table".
    void remove(int key) {
        int i = hashFunction(key);
        table[i].remove(key);
    }

    // Hash function: h(k) = k % m (where k is the key and m is the size of the table).
    int hashFunction(int key) {
        return key % tableSize;
    }

    void display() {
        return;
    }

};

int main (int argc, char **argv) {

    HashTable ht(10);

    ht.insert(10);
    ht.insert(5);
    ht.insert(7);

}