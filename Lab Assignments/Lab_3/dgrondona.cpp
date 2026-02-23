#include <iostream>
using namespace std;

int findMaxCrossingSubArray(int* A, int low, int mid, int high) {

    int maxLeft, maxRight;

    int leftSum = -999999;
    int sum = 0;

    for (int i = mid; i > low; i--) {

        sum = sum + A[i];

        if (sum > leftSum) {

            leftSum = sum;
            maxLeft = i;

        }

    }

    int rightSum = -999999;
    int sum = 0;

    for (int j = mid + 1; j < high; j++) {

        sum = sum + A[j];

        if (sum > rightSum) {

            rightSum = sum;
            maxRight = j;

        }

    }

    return (maxLeft, maxRight, leftSum + rightSum);

}

int findMaxSubArray(int* A, int low, int high) {

    if (high == low) {

        return (low, high, A[low]);

    } else {

        int mid = ((low + high) / 2);

        int leftHigh, leftLow, leftSum = findMaxSubArray(A, low, mid);
        int rightLow, rightHigh, rightSum = findMaxSubArray(A, mid + 1, high);
        int crossLow, crossHigh, crossSum = findMaxCrossingSubArray(A, low, mid, high);

        if (leftSum >= rightSum && leftSum >= crossSum) {

            return (leftLow, leftHigh, leftSum);

        } else if (rightSum >= leftSum && rightSum >= crossSum) {

            return (rightLow, rightHigh, rightSum);

        } else {

            return (crossLow, crossHigh, crossSum);

        }


    }

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