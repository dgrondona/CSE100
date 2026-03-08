#include <iostream>

using namespace std;

int** countingSort(int** A, int n, int d) {

    int** B = new int*[n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[10];
    }

    int C[4] = {0}; // values are {0,1,2,3}

    // Count occurrences
    for (int i = 0; i < n; i++) {
        int digit = A[i][d];
        C[digit]++;
    }

    // Prefix sum
    for (int j = 1; j < 4; j++) {
        C[j] += C[j - 1];
    }

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {

        int digit = A[i][d];
        int pos = C[digit] - 1;

        for (int k = 0; k < 10; k++) {
            B[pos][k] = A[i][k];
        }

        C[digit]--;
    }

    return B;
}

void radixSort(int** A, int n) {

    for (int d = 9; d >= 0; d--) {

        int** B = countingSort(A, n, d);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                A[i][j] = B[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            delete[] B[i];
        }
        delete[] B;
    }
}

int main(int argc, char **argv) {

    int size;

    cin >> size;

    int** input = new int*[size];

    for (int i = 0; i < size; i++) {
        input[i] = new int[10];
    }

    // Read vectors
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> input[i][j];
        }
    }

    radixSort(input, size);

    // Output format
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < 10; j++) {
            cout << input[i][j] << ";";
        }

        cout << endl;
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        delete[] input[i];
    }
    delete[] input;
}