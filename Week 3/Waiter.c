#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Function to check prime
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// Generate first q primes
void generatePrimes(int primes[], int q) {
    int count = 0, num = 2;
    while (count < q) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    int A[MAX];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    int primes[q];
    generatePrimes(primes, q);

    int topA = n - 1;
    
    for (int i = 0; i < q; i++) {
        int B[MAX], topB = -1;
        int newA[MAX], topNewA = -1;
        
        while (topA >= 0) {
            int plate = A[topA--];
            if (plate % primes[i] == 0) {
                B[++topB] = plate;
            } else {
                newA[++topNewA] = plate;
            }
        }
        
        // print B stack
        while (topB >= 0) printf("%d\n", B[topB--]);
        
        // copy back A
        for (int j = 0; j <= topNewA; j++)
            A[j] = newA[j];
        topA = topNewA;
    }
    
    // print remaining A stack
    while (topA >= 0) printf("%d\n", A[topA--]);

    return 0;
}
