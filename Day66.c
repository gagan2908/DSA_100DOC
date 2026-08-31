#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int **adj, int *size, int *visited, int *recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, size, visited, recStack))
                return 1;
        }
        else if (recStack[neighbor]) {
            // Back edge found -> cycle
            return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = malloc(V * sizeof(int *));
    int *size = calloc(V, sizeof(int));
    int *capacity = calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        capacity[i] = 2;
        adj[i] = malloc(capacity[i] * sizeof(int));
    }

    // Directed edges: u -> v
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (size[u] == capacity[u]) {
            capacity[u] *= 2;
            adj[u] = realloc(adj[u], capacity[u] * sizeof(int));
        }

        adj[u][size[u]++] = v;
    }

    int *visited = calloc(V, sizeof(int));
    int *recStack = calloc(V, sizeof(int));

    int cycle = 0;

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, size, visited, recStack)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    for (int i = 0; i < V; i++)
        free(adj[i]);

    free(adj);
    free(size);
    free(capacity);
    free(visited);
    free(recStack);

    return 0;
}