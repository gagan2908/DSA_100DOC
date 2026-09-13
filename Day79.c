#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int d, v;
} Node;

Edge *adj[100005];
int degree[100005];

Node heap[1000005];
int size = 0;

void push(int d, int v) {
    int i = ++size;

    while (i > 1 && d < heap[i / 2].d) {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i].d = d;
    heap[i].v = v;
}

Node pop() {
    Node result = heap[1];
    Node last = heap[size--];

    int i = 1;

    while (2 * i <= size) {
        int child = 2 * i;

        if (child + 1 <= size &&
            heap[child + 1].d < heap[child].d) {
            child++;
        }

        if (last.d <= heap[child].d)
            break;

        heap[i] = heap[child];
        i = child;
    }

    heap[i] = last;
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = malloc(1 * sizeof(Edge));
        degree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u] = realloc(adj[u],
                         (degree[u] + 1) * sizeof(Edge));

        adj[u][degree[u]].v = v;
        adj[u][degree[u]].w = w;
        degree[u]++;
    }

    int source;
    scanf("%d", &source);

    int dist[100005];

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(0, source);

    while (size > 0) {
        Node cur = pop();
        int u = cur.v;

        if (cur.d != dist[u])
            continue;

        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF");
        else
            printf("%d", dist[i]);

        if (i < n)
            printf(" ");
    }

    printf("\n");

    for (int i = 1; i <= n; i++)
        free(adj[i]);

    return 0;
}