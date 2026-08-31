#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int **adj, int *size, int *visited) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, size, visited))
                return 1;
        }
        else if (neighbor != parent) {
            return 1;
        }
    }

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

    // Build adjacency list
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (size[u] == capacity[u]) {
            capacity[u] *= 2;
            adj[u] = realloc(adj[u], capacity[u] * sizeof(int));
        }
        adj[u][size[u]++] = v;

        if (size[v] == capacity[v]) {
            capacity[v] *= 2;
            adj[v] = realloc(adj[v], capacity[v] * sizeof(int));
        }
        adj[v][size[v]++] = u;
    }

    int *visited = calloc(V, sizeof(int));
    int cycle = 0;

    // Check every component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, size, visited)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    // Free memory
    for (int i = 0; i < V; i++)
        free(adj[i]);

    free(adj);
    free(size);
    free(capacity);
    free(visited);

    return 0;
}