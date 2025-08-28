#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort to sort house positions
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hackerlandRadioTransmitters(int x_count, int* x, int k) {
    // Sort house locations
    qsort(x, x_count, sizeof(int), cmp);

    int i = 0, transmitters = 0;

    while (i < x_count) {
        transmitters++;

        // Place transmitter to cover house x[i]
        int loc = x[i] + k;

        // Move i to right while house is within transmitter range
        while (i < x_count && x[i] <= loc)
            i++;

        // Place transmitter at house before exceeding coverage range
        loc = x[i - 1] + k;

        // Skip houses covered by transmitter at loc
        while (i < x_count && x[i] <= loc)
            i++;
    }

    return transmitters;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int x[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    int result = hackerlandRadioTransmitters(n, x, k);
    printf("%d\n", result);

    return 0;
}
