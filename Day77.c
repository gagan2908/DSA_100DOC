#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **graph = malloc((n + 1) * sizeof(int *));
    int *degree = calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++) {
        graph[i] = malloc((m + 1) * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][degree[u]++] = v;
        graph[v][degree[v]++] = u;
    }

    int *visited = calloc(n + 1, sizeof(int));
    int *queue = malloc((n + 1) * sizeof(int));

    int front = 0, rear = 0;

    queue[rear++] = 1;
    visited[1] = 1;

    while (front < rear) {
        int u = queue[front++];

        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i];

            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}