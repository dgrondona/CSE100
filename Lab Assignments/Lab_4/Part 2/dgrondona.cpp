#include <iostream>

// For random number
#include <cstdlib>
#include <ctime>

using namespace std;


int partition(int* A, int low, int high) {

    // Choose the center as the pivot (FIX ME: Use random later)
    int i = low + rand() % (high - low + 1);
    int pivot = A[i];

    // Swap the pivot with the last element
    int tmp = A[i];
    A[i] = A[high];
    A[high] = tmp;

    i = low;

    for (int j = low; j <= high - 1; j++) {

        if (A[j] <= pivot) {

            // Swap A[i] and A[j]
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;

            i++;

        }

    }

    // Swap pivot between smaller and larger elemets
    tmp = A[i];
    A[i] = A[high];
    A[high] = tmp;

    return i;

}

void quickSort(int* A, int low, int high) {

    if (low < high) {

        // Partition array and get index
        int i = partition(A, low, high);

        // Sort before pivot
        quickSort(A, low, i - 1);
        // Sor after pivot
        quickSort(A, i + 1, high);

    }

}


int main(int argc, char **argv) {

    // Seed the random number gen
    srand(time(0));

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
    quickSort(input, 0, size - 1);

    // Output the array
    for (int i = 0; i < size; i++) {
        std::cout << input[i] << ";";
    }

    // Free memory
    delete[] input;

}