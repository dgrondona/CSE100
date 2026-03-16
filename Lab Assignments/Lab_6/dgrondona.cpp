#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:

    // Define tableSize and the table as a vector of linked lists.
    int tableSize;
    std::vector<list<int>> table;

public:

    // Constructor. Take in the size and set the table size to that.
    HashTable(int size) {
        tableSize = size;
        table.resize(size);
    }

    // Insert key into table; i2 implies "Insert key 2 into the table".
    void insert(int key) {
        int i = hashFunction(key);
        table[i].push_front(key); // Push Front so that collisions go the the beginning of the list.
    }

    // Search table for key.
    bool search(int key, int &slot, int &pos) {

        slot = hashFunction(key);
        pos = 0;

        // If a value in the hash table matches a key, return true. We also track the position and get the slot from the hash function.
        for (int val : table[slot]) {
            if (val == key) {
                return true;
            }
            pos++;
        }

        return false;
    }

    // Delete key from the table; d2 implies “Delete key 2 from the table".
    bool remove(int key) {

        // Find the bucket that the index is in.
        int index = hashFunction(key);

        // Iterate from the start of the linked list to the end.
        for (auto it = table[index].begin(); it != table[index].end(); it++) {

            // If the element from our iterator == key, remove the node and return true.
            if (*it == key) {
                table[index].erase(it);
                return true;
            }

        }
        // Otherwise return false.
        return false;
    }

    // Hash function: h(k) = k % m (where k is the key and m is the size of the table).
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Print out the Hash Table.
    void output() {
        
        for (int i = 0; i < tableSize; i++) {

            std::cout << i << ":";

            for (int val : table[i]) {
                std::cout << val << "->";
            }

            std::cout << ";" << std::endl;

        }

    }

};

int main (int argc, char **argv) {

    int m;

    std:cin >> m;

    HashTable ht(m);

    char command;

    // Handle the commands to determine if a number is inserted, deleted, etc.
    while (std::cin >> command) {

        if (command == 'e') {
            break;
        } else if (command == 'i') {

            int key;
            std::cin >> key;
            ht.insert(key);

        } else if (command == 's') {

            int key;
            std::cin >> key;

            int slot, pos;

            if (ht.search(key, slot, pos)) {
                std::cout << key << ":FOUND_AT" << slot << "," << pos << ";" << std::endl;
            } else {
                std::cout << key << ":NOT_FOUND;" << std::endl;
            }

        } else if (command == 'd') {

            int key;
            std::cin >> key;

            if (ht.remove(key)) {
                std::cout << key << ":DELETED;" << std::endl;
            } else {
                std::cout << key << ":DELETE_FAILED;" << std::endl;
            }

        } else if (command == 'o') {

            ht.output();

        }

    }

}