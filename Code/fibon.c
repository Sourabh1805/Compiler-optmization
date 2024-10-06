// your_program.c
#include <stdio.h>
#include <time.h>

static void generateFibonacci(int n) {
    int fib1 = 0, fib2 = 1, next;

    
    for (int i = 3; i <= n; ++i) {
        next = fib1 + fib2;
        
        fib1 = fib2;
        fib2 = next;
    }
    
}

int main() {
    long long sum = 0;
    int i;

    // Start measuring time
    clock_t start = clock();

    int n=100;


    
    generateFibonacci(n);
    

    // End measuring time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the result and the execution time
    printf("%lld\n");
    printf("%f\n", time_spent);

    return 0;
}

