#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size, top;
    int *a;
}stack;

int isEmpty(stack *);
int isFull(stack *);
void resize(stack *);
void push(stack *, int);
int pop(stack *);
void dfs(int **, stack *, int, int, int);

int isEmpty(stack *s) {
    return (s->top == -1);
}

int isFull(stack *s) {
    return ( s->top == s->size - 1);
}

void resize(stack *s) {
        s->size *= 2;
        s->a = realloc(s->a, s->size * sizeof(int));
}

void push(stack *s, int data) {
    if(isFull(s)) {
        resize(s);
    }
    s->a[++s->top] = data;
}

int pop(stack *s) {
    return s->a[s->top--];
}

void dfs(int **adj, stack *s, int start, int goal, int n) {
    int *visited = (int *)calloc(n, sizeof(int));

    
    visited[start] = 1;
    push(s, start);
    while(!isEmpty(s)) {
        int node = pop(s);
        printf("%d ", node);
        if(node == goal) {
            break;
        }
        for(int j = n - 1;j > -1;j--) {
            if(adj[node][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                push(s, j);
            }
        }
    }
    free(visited);
}

int main() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->a = (int *)malloc(s->size * sizeof(int));

    int n;
    printf("Enter the number of nodes in the graph:");
    scanf("%d", &n);
    
    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0;i < n;i++) {
        adj[i] = (int *)calloc(n, sizeof(int));
    }
    
    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            printf("Is there edge from %d to %d?\n", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    // adj[0][1] = 1;
    // adj[0][2] = 1;
    // adj[1][3] = 1;
    // adj[1][4] = 1;
    // adj[2][5] = 1;
    // adj[2][6] = 1;

    // adj[1][0] = 1;
    // adj[2][0] = 1;
    // adj[3][1] = 1;
    // adj[4][1] = 1;
    // adj[5][2] = 1;
    // adj[6][2] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
    int start, goal;
    printf("Enter the starting and the goal node:");
    scanf("%d%d", &start, &goal);
    
    dfs(adj, s, start, goal, n);

    free(s->a);
    free(s);
    for (int i = 0;i < n;i++) {
        free(adj[i]);
    }
    free(adj);
    return 0;
}