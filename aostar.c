#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20  

struct Node {
    int val;
    int cost;  
    bool isAndNode;  
    int children[2];  
    int numChildren;  
};

int AOStar(int node, struct Node graph[], int n, int solution[]) {
    if (graph[node].numChildren == 0) {
        solution[node] = node;  
        return graph[node].cost;
    }

    int minCost = INT_MAX;  

    if (graph[node].isAndNode) {
        int cost1 = AOStar(graph[node].children[0], graph, n, solution);
        int cost2 = AOStar(graph[node].children[1], graph, n, solution);
        minCost = cost1 + cost2 + graph[node].cost;
        solution[node] = node;  
    } else {
        for (int i = 0; i < graph[node].numChildren; i++) {
            int cost = AOStar(graph[node].children[i], graph, n, solution);
            if (cost < minCost) {
                minCost = cost;
                solution[node] = node;  
            }
        }
    }

    return minCost;
}

int main() {
    // Graph has 7 nodes where:
    // Nodes 0, 3, 4 are OR nodes; Nodes 1, 2, 5, 6 are AND nodes
    struct Node graph[MAX] = {
        {0, 0, false, {1, 2}, 2},  
        {1, 1, true, {3, 4}, 2},  
        {2, 2, true, {5, 6}, 2},  
        {3, 3, false, {}, 0},      
        {4, 4, false, {}, 0},      
        {5, 5, false, {}, 0},      
        {6, 6, false, {}, 0}       
    };

    int solution[MAX] = {0}; 
    int startNode = 0;  
    
    int result = AOStar(startNode, graph, MAX, solution);

    printf("Optimal Solution Path: \n");
    for (int i = 0; i < MAX; i++) {
        if (solution[i] != 0) {
            printf("Node %d -> ", solution[i]);
        }
    }
    printf("\nTotal Cost: %d\n", result);

    return 0;
}