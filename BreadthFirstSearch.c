#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size, front, rear;
    int *a;
}queue;

int isEmpty(queue *);
int isFull(queue *);
void resize(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
void bfs(int **, queue *, int, int, int);

int isEmpty(queue *q) {
    return (q->front == q->rear);
}

int isFull(queue *q) {
    return (q->rear == q->size - 1);
}

void resize(queue *q) {
    q->size *= 2;
    q->a = realloc(q->a, q->size * sizeof(int));
}

void enqueue(queue *q, int data) {
    if(isFull(q)) {
        resize(q);
    }
    q->a[++q->rear] = data;
}

int dequeue(queue *q) {
    return q->a[++q->front];
}

void bfs(int **adj, queue *q, int start, int goal, int n) {
    int *visited = (int *)calloc(n, sizeof(int));

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int node = dequeue(q);
        printf("%d ",node);
        if(node == goal) {
            break;
        }
        for (int j = 0;j < n;j++) {
            if(adj[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
    free(visited);
}

int main() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->a = (int *)malloc(q->size * sizeof(int));

    int n;
    printf("Enter the number of nodes in the graph:");
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    for(int i= 0;i < n;i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }
    
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            printf("Is there edge from %d to %d?\n", i, j);
            scanf("%d", &adj[i][j]);
            adj[j][i] = adj[i][j];
        }
    }

    int start, goal;
    printf("Enter the starting and the goal node:");
    scanf("%d%d", &start, &goal);

    bfs(adj, q, start, goal, n);
    
    free(q->a);
    free(q);
    for (int i = 0;i < n;i++) {
        free(adj[i]);
    }
    free(adj);
    return 0;
}