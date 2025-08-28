#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int heap[MAX];
int heap_size = 0;
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void insert(int value) {
    heap[heap_size++] = value;
    qsort(heap, heap_size, sizeof(int), cmpfunc); 
}
void delete(int value) {
    for (int i = 0; i < heap_size; i++) {
        if (heap[i] == value) {
            for (int j = i; j < heap_size - 1; j++) {
                heap[j] = heap[j + 1];
            }
            heap_size--;
            break;
        }
    }
}
int get_min() {
    return heap[0];
}
int main() {
    int Q, type, val;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            insert(val);
        } else if (type == 2) {
            scanf("%d", &val);
            delete(val);
        } else if (type == 3) {
            printf("%d\n", get_min());
        }
    }
    return 0;
}
