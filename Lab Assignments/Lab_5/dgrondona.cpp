#include <iostream>

using namespace std;

void radixSort(int* A, int low, int high) {

    

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
    
    // Radix Sort
    radixSort(input, 0, size - 1);

    // Output the array
    for (int i = 0; i < size; i++) {
        std::cout << input[i] << ";";
    }

    // Free memory
    delete[] input;

}