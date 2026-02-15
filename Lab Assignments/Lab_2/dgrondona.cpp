#include <iostream>
using namespace std;

int* merge(int* left, int* right, int leftHalf, int rightHalf) {

    int size = leftHalf + rightHalf;
    int* result = new int[size];

    int a = 0;
    int b = 0;

    for (int i = 0; i < (size); i++) {

        // std::cerr << "a: " << a << ",  b: " << b << ",  size: " << size << std::endl;

        if (b >= rightHalf || (a < leftHalf && left[a] < right[b])) {

            // std::cerr << "merging left: " << left[a] << std::endl;

            result[i] = left[a++];

        } else {

            // std::cerr << "merging right: " << right[b] << std::endl;

            result[i] = right[b++];

        }

    }

    return result;

}

// Mergesort Function
int* mergesort(int* input, int size) {

    int* result;

    if (size <= 1) {
        result = new int[1];
        result[0] = input[0];
        return result;
    }

    // int division automatically truncated
    int leftHalf = size / 2;
    int rightHalf = size - leftHalf;

    // Run sort with the left and right half of the array
    int* left = mergesort(input, leftHalf);
    int* right = mergesort(input + leftHalf, rightHalf);

    // Merge the 2 halves
    result = merge(left, right, leftHalf, rightHalf);

    // Dealocate memory
    delete[] left;
    delete[] right;

    return result;

}

int main(int argc, char **argv) {

    // Variables to get our inputted size and contents
    int* input;
    int size;

    // Get the size from the first input and make an array of that size
    std::cin >> size;
    // std::cout << "--------" << size << ", " << (size % 2) << std::endl;
    input = new int[size];

    // Fill the array with elements from the input
    for (int i = 0; i < size; i++) {

        std::cin >> input[i];

    }
    
    // Mergesort
    int* result = mergesort(input, size);

    // Print the array
    for (int i = 0; i < size; i++) {

        std::cout << result[i] << ";";

    }

    // Free allocated memory
    delete[] result;
    delete[] input;

}