#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pt;
    int dist;
} QueueNode;

typedef struct {
    int front, rear, size;
    unsigned capacity;
    QueueNode* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (QueueNode*) malloc(queue->capacity * sizeof(QueueNode));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, QueueNode item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

QueueNode dequeue(Queue* queue) {
    QueueNode item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}

int minimumMoves(char** grid, int n, int startX, int startY, int goalX, int goalY) {
    bool visited[MAX][MAX] = {false};
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    Queue* queue = createQueue(n*n);
    
    enqueue(queue, (QueueNode){{startX, startY}, 0});
    visited[startX][startY] = true;

    while (!isEmpty(queue)) {
        QueueNode curr = dequeue(queue);
        int x = curr.pt.x, y = curr.pt.y, dist = curr.dist;
        if (x == goalX && y == goalY)
            return dist;

       
        for (int d = 0; d < 4; d++) {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'X') {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    enqueue(queue, (QueueNode){{nx, ny}, dist + 1});
                }
                nx += directions[d][0];
                ny += directions[d][1];
            }
        }
    }
    return -1; 
}

int main() {
    int n;
    scanf("%d", &n);
    char** grid = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc((n + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }
    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int result = minimumMoves(grid, n, startX, startY, goalX, goalY);
    printf("%d\n", result);

    for (int i = 0; i < n; i++)
        free(grid[i]);
    free(grid);

    return 0;
}

