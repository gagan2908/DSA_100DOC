#include <stdio.h>

#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int dist[n][n];

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("-1");
            } else {
                printf("%d", dist[i][j]);
            }

            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}