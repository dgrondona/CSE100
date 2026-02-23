#include <iostream>
using namespace std;

// the bit integer limit so any value is greater than MIN
int MIN = -2147483648;

// Struct to hold low, high, and sum
struct SubArray {
    int low;
    int high;
    int sum;
};

SubArray findMaxCrossingSubArray(int* A, int low, int mid, int high) {

    int leftSum = MIN;
    int maxLeft = mid;
    int sum = 0;

    for (int i = mid; i >= low; i--) {

        sum += A[i];

        if (sum > leftSum) {

            leftSum = sum;
            maxLeft = i;

        }

    }

    int rightSum = MIN;
    int maxRight = mid + 1;
    sum = 0;

    for (int j = mid + 1; j <= high; j++) {

        sum += A[j];

        if (sum > rightSum) {

            rightSum = sum;
            maxRight = j;

        }

    }

    return {maxLeft, maxRight, leftSum + rightSum};

}

SubArray findMaxSubArray(int* A, int low, int high) {

    if (high == low) {

        return {low, high, A[low]};

    } else {

        int mid = ((low + high) / 2);

        SubArray left = findMaxSubArray(A, low, mid);
        SubArray right = findMaxSubArray(A, mid + 1, high);
        SubArray cross = findMaxCrossingSubArray(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) {

            return left;

        } else if (right.sum >= left.sum && right.sum >= cross.sum) {

            return right;

        } else {

            return cross;

        }


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
    
    // Find Maximum Sub-Array
    SubArray result = findMaxSubArray(input, 0, size - 1);

    // Output the sum
    std::cout << result.sum;

    // Free memory
    delete[] input;

}