#include <iostream>
using namespace std;

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

    // Initialize variables for our sorting function
    int key = 0;
    int j = 0;

    // Sort
    for (int i = 2; i < size; i++) {

        key = input[i];
        j = i - 1;

        while (j > 0 && input[j] > key) {

            input[j + 1] = input[j];
            j = j - 1;

        }

        input[j + 1] = key;

        // Output
        for (int k = 0; k < size; k++) {
            std::cout << input[k] << ";";
        }

        std::cout << std::endl;

    }

    // Free allocated memory
    delete[] input;

}