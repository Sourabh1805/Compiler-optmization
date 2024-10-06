// your_program.c
#include <stdio.h>
#include <time.h>

int main() {
    int i;
    long long cube;

    // Start measuring time
    clock_t start = clock();

   

    // Loop from 1 to 500
    for (i = 1; i <= 500; i++) {
        // Calculate cube
        cube = (long long)i * i * i;
        // Display the result
        
    }

 

    // End measuring time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the result and the execution time
    printf("%lld\n", cube);
    printf("%f\n", time_spent);

    return 0;
}

