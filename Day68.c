#include <stdio.h>

void topologicalSort(int V, int adj[V][V]) {
    int indegree[V];
    int queue[V];
    int front = 0, rear = 0;
    int count = 0;

    // Calculate in-degree of every vertex
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Kahn's Algorithm
    while (front < rear) {
        int u = queue[front++];

        printf("%d ", u);
        count++;

        // Remove outgoing edges
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // If not all vertices are processed, graph has a cycle
    if (count != V) {
        printf("\nCycle detected - Topological sort not possible");
    }
}

int main() {
    int V, E;

    scanf("%d %d", &V, &E);

    int adj[V][V];

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
    }

    topologicalSort(V, adj);

    return 0;
}