#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    int key[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    int total = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        // Select the unvisited vertex with minimum key
        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        total += key[u];

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total);

    return 0;
}