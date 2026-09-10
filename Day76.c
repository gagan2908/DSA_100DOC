#include <stdio.h>

int graph[100][100];
int visited[100];
int n, m;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;   // Undirected graph
    }

    int components = 0;

    // Check every vertex
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            components++;
            dfs(i);
        }
    }

    printf("%d\n", components);

    return 0;
}