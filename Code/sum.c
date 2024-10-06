// your_program.c
#include <stdio.h>
#include <time.h>

int main() {
    long long sum = 0;
    int i;

    // Start measuring time
    clock_t start = clock();

    for (i = 0; i < 10000000; i++) {
        sum += i;
    }

    // End measuring time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the result and the execution time
    printf("%lld\n", sum);
    printf("%f\n", time_spent);

    return 0;
}

