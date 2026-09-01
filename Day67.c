#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int V, int **adj, int *visited, int *stack, int *top) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, V, adj, visited, stack, top);
        }
    }

    // Add node after all adjacent nodes are processed
    stack[(*top)++] = node;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Adjacency matrix
    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)calloc(V, sizeof(int));
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    int *visited = (int *)calloc(V, sizeof(int));
    int *stack = (int *)malloc(V * sizeof(int));
    int top = 0;

    // DFS for every unvisited vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V, adj, visited, stack, &top);
        }
    }

    printf("Topological Ordering: ");

    // Print in reverse finishing order
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");

    // Free memory
    for (int i = 0; i < V; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    free(stack);

    return 0;
}