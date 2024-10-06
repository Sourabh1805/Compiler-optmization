#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void matrixMultiply(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    // Initialize the result matrix C to zero
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0.0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}



int main() {
    long long sum = 0;
    int timeeee;

    // Start measuring time
    clock_t start = clock();
    // Seed for random number generation
    srand(0);

    // Generate two random 50x50 matrices
    double matrix1[SIZE][SIZE];
    double matrix2[SIZE][SIZE];
    double result[SIZE][SIZE];

    // Initialize matrices with random values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix1[i][j] = (double)rand() / RAND_MAX;
            matrix2[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Perform matrix multiplication
    matrixMultiply(matrix1, matrix2, result);

   

     // End measuring time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the result and the execution time
    printf("%lld\n", sum);
    printf("%f\n", time_spent);

    return 0;
}
