#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int heap_size = 0;

// Sort comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Push to heap (insert at end and sort)
void push(int val) {
    heap[heap_size++] = val;
    qsort(heap, heap_size, sizeof(int), cmp);
}

// Pop minimum (first element) and shift array
int pop_min() {
    int min = heap[0];
    for (int i = 1; i < heap_size; i++)
        heap[i - 1] = heap[i];
    heap_size--;
    return min;
}

// Main cookies function
int cookies(int k, int A[], int n) {
    heap_size = 0;
    for (int i = 0; i < n; i++)
        push(A[i]);

    int ops = 0;
    while (heap_size >= 2 && heap[0] < k) {
        int least = pop_min();
        int second = pop_min();
        int new_cookie = least + 2 * second;
        push(new_cookie);
        ops++;
    }

    return (heap[0] >= k) ? ops : -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int result = cookies(k, A, n);
    printf("%d\n", result);
    return 0;
}
