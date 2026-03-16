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
    HashTable(int size);

    void insert(int key);
    bool search(int key);
    void remove(int key);

    void display();
};