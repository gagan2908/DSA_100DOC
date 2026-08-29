#include <stdio.h>

#define MAX 100

int main() {
    int n, m, s;
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0, rear = 0;

    // Input number of vertices
    scanf("%d", &n);

    // Input number of edges
    scanf("%d", &m);

    // Input adjacency list as edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;   // Remove this for directed graph
    }

    // Source vertex
    scanf("%d", &s);

    // BFS
    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int u = queue[front++];

        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}