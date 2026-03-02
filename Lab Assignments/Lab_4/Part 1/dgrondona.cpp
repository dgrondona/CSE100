#include <iostream>
using namespace std;

// Helper functions to return indexing for left and right
int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}


// 
void maxHeapify(int* A, int i, int heapSize) {

    // Set left child, right child, and assume current node is largest
    int l = left(i);
    int r = right(i);
    int largest = i;

    // If left child exists and is larger than current largest, set largest to left child
    if (l < heapSize && A[l] > A[largest]) {
        largest = l;
    }

    // If right child exists and is larger than current largest, set largest as right child
    if (r < heapSize && A[r] > A[largest]) {
        largest = r;
    }

    // If a child is larger than the parent, swap them and run again
    if (largest != i) {

        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;

        maxHeapify(A, largest, heapSize);

    }

}


// Build a max heap from unsorted array
void buildMaxHeap(int* A, int size) {

    // Start at last node and move backwards until we get to the root
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(A, i, size);
    }

}


// Heap Sort Algorithm
void heapSort(int* A, int size) {

    // Convert our array into a max heap
    buildMaxHeap(A, size);

    // Move largest element to the end, then fix rest of array with maxHeapify
    for (int i = size - 1; i > 0; i--) {

        int tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;

        maxHeapify(A, 0, i);

    }

}


int main(int argc, char **argv) {

    // Variables to get our inputted size and contents
    int* input;
    int size;

    // Get the size from the first input and make an array of that size
    std::cin >> size;

    input = new int[size];

    // Fill the array with elements from the input
    for (int i = 0; i < size; i++) {

        std::cin >> input[i];

    }
    
    // Heap Sort
    heapSort(input, size);

    // Output the array
    for (int i = 0; i < size; i++) {
        std::cout << input[i] << ";";
    }

    // Free memory
    delete[] input;

}